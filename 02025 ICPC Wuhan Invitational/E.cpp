#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct edge {
    int u, v, id;
    int other(int x) { return x == u ? v : u; }
};

void solve() {

    int n, m; cin >> n >> m;
    vector<vector<edge>> G(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge e = {u, v, i};
        G[u].push_back(e);
        G[v].push_back(e);
    }

    vector<int> cur0(n + 1);
    vector<bool> marked0(n + m + 5);

    // 得到边序列之后要 reverse
    auto hierholzer_edge = [&](auto &&self, int u, vector<edge> &vec) -> void {
        while (cur0[u] < G[u].size()) {
            edge e = G[u][cur0[u]++];
            if (marked0[e.id]) continue;
            marked0[e.id] = true;
            self(self, e.other(u), vec);
            vec.push_back(e);
        }

    };

    vector<int> cur1(n + 1);
    vector<bool> marked1(n + m + 5);

    // 得到顶点序列之后要 reverse
    auto hierholzer_vertice = [&](auto &&self, int u, vector<int> &vec) -> void {
        while (cur1[u] < G[u].size()) {
            edge e = G[u][cur1[u]++];
            if (marked1[e.id]) continue;
            marked1[e.id] = true;

            int v = e.other(u);
            self(self, v, vec);
        }

        vec.push_back(u);
    };

    vector<bool> marked(n + 1);
    vector<int> modified;

    int cid = m;

    auto build = [&](auto &&self, int u) -> void {
        marked[u] = true;
        for (edge &e : G[u]) {
            int v = e.other(u);
            if (marked[v]) continue;
            self(self, v);
        }

        if (G[u].size() & 1) {
            modified.push_back(u);
            edge e = {0, u, ++cid};
            G[u].push_back(e);
            G[0].push_back(e);
        }
    };

    auto destruct = [&]() -> void {
        G[0].clear();
        for (int x : modified) {
            G[x].pop_back();
        }
        modified.clear();

        cur0[0] = 0;
        cur1[0] = 0;
    };

    vector<bool> onstack(n + 1);
    int color = 1;

    vector<int> ans(m + n + 1);

    for (int u = 1; u <= n; u++) {
        if (marked[u]) continue;
        build(build, u);

        vector<int> verts;
        vector<edge> edges;
        hierholzer_vertice(hierholzer_vertice, u, verts);
        hierholzer_edge(hierholzer_edge, u, edges);
        reverse(verts.begin(), verts.end());
        reverse(edges.begin(), edges.end());

        stack<edge> stke;
        stack<int> stkv;
        onstack[verts[0]] = true;
        stkv.push(verts[0]);

        for (int i = 1; i < verts.size(); i++) {
            if (onstack[verts[i]]) {
                ans[edges[i - 1].id] = color;
                while (stkv.top() != verts[i]) {
                    onstack[stkv.top()] = false;
                    ans[stke.top().id] = color;
                    stke.pop();
                    stkv.pop();
                }
                ++color;
            } else {
                onstack[verts[i]] = true;
                stkv.push(verts[i]);
                stke.push(edges[i - 1]);
            }
        }

        destruct();
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}