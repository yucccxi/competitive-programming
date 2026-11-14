#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 2e9;

struct Edge {
    int u, v;
    int other(int x) { return x == u ? v : u; }
};

pair<int, Edge> findmid(int n, vector<vector<Edge>> T) {
    vector<int> dist(n + 1, INF);
    vector<Edge> to(n + 1);
    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (Edge &e : T[u]) {
            int v = e.other(u);
            if (v == p) continue;
            dist[v] = dist[u] + 1;
            to[v] = e;
            self(self, v, u);
        }
    };

    dist[1] = 0;
    dfs(dfs, 1, 0);

    int mxd = 0, mxv = 0;
    for (int i = 1; i <= n; i++) {
        assert(dist[i] != INF);
        if (dist[i] > mxd) {
            mxd = dist[i];
            mxv = i;
        }
    }

    dist[mxv] = 0;
    dfs(dfs, mxv, 0);

    mxd = 0, mxv = 0;
    for (int i = 1; i <= n; i++) {
        assert(dist[i] != INF);
        if (dist[i] > mxd) {
            mxd = dist[i];
            mxv = i;
        }
    }

    int cur = mxv;
    for (int i = 0; i < mxd / 2; i++) {
        Edge e = to[cur];
        cur = e.other(cur);
    }

    return {mxd, to[cur]};
}

void solve() {
    int n; cin >> n;
    vector<vector<Edge>> T(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;

        Edge e = {u, v};
        T[u].push_back(e);
        T[v].push_back(e);
    }

    pair<int, Edge> ret = findmid(n, T);

    int len  = ret.first ;
    Edge mid = ret.second;

    set<int> lall, rall;

    auto dfs = [&](auto &&self, int u, int p, int d, set<int> &st) -> bool {
        int tot = 0, cnt = 0;
        for (Edge &e : T[u]) {
            int v = e.other(u);
            if (v == p) continue;
            int ntot = self(self, v, u, d + 1, st);
            if (ntot > 0) cnt++;
            tot += ntot;
        }

        if (cnt >= 2 || d == len / 2) {
            st.insert(d);
        }

        if (d == len / 2) return 1;
        return tot;
    };

    dfs(dfs, mid.u, mid.v, 0, lall);
    dfs(dfs, mid.v, mid.u, 0, rall);

    set<int> ans;
    for (int x : lall) {
        for (int y : rall) {
            ans.insert(x + y + 1);
        }
    }

    cout << ans.size() << " ";
    for (int x : ans) {
        cout << x << " ";
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