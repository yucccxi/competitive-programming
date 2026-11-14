#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 5e5 + 5;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &o) const {
        return w < o.w;
    }
};

int n, m, k;
vector<Edge> edges;

vector<int> G[MAXN];

struct Cmp {
    bool operator()(const int i, const int j) const {
        return edges[i].w > edges[j].w;
    }
};

struct Item {
    int u, pos;

    bool operator<(const Item &o) const {
        return edges[G[u][pos]].w < edges[G[o.u][o.pos]].w;
    }

    bool operator>(const Item &o) const {
        return edges[G[u][pos]].w > edges[G[o.u][o.pos]].w;
    }
};

priority_queue<Item, vector<Item>, greater<Item>> pq[MAXN];

vector<int> ans;

void solve0(int weight) {
    if (ans.size() >= k) return;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            int id = G[i][j];
            if (edges[id].w == weight) {
                pq[1].push({i, j});
                break;
            }
        }
    }

    int lvl = 1;
    while (lvl > 0) {
        if (pq[lvl].size() == 0) {
            --lvl;
            continue;
        }

        auto fst = pq[lvl].top();
        int curw = edges[G[fst.u][fst.pos]].w;

        while (pq[lvl].size() > 0) {
            auto [u, pos] = pq[lvl].top();
            if (edges[G[u][pos]].w != curw) break;

            pq[lvl].pop();

            ans.push_back(lvl);
            if (ans.size() >= k) return;

            int npos = pos + 1;
            if (npos < G[u].size()) {
                if (lvl != 1 || edges[G[u][npos]].w == weight) {
                    pq[lvl].push({u, npos});
                }
            }

            int v = edges[G[u][pos]].v;

            if (G[v].size() > 0) {
                pq[lvl + 1].push({v, 0});
            }
        }

        ++lvl;
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(edges.size());
        edges.push_back({u, v, w});
    }

    for (int u = 1; u <= n; u++) {
        sort(G[u].begin(), G[u].end(), [&](const int i, const int j) -> bool {
            return edges[i].w < edges[j].w;
        });
    }

    for (int i = 1; i <= 8; i++) {
        solve0(i);
    }

    assert(ans.size() <= k);

    for (int x : ans) {
        cout << x << endl;
    }

    for (int i = 0; i < k - ans.size(); i++) {
        cout << -1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}