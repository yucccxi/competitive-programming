#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 2e9;
const ll LINF = 9e18;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> G(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> parent(n + 1), child(n + 1), depth(n + 1), top(n + 1), sz(n + 1);
    vector<ll> f(n + 1);
    auto dfs0 = [&](auto &&self, int u, int p) -> void {
        parent[u] = p;
        depth[u] = depth[p] + 1;
        sz[u] = 1;

        for (int v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            sz[u] += sz[v];

            if (!child[u] || sz[v] > sz[child[u]]) {
                child[u] = v;
            }
        }
    };

    auto dfs1 = [&](auto &&self, int u, int tp) -> void {
        top[u] = tp;

        if (child[u]) {
            self(self, child[u], tp);
        }

        for (int v : G[u]) {
            if (v == parent[u] || v == child[u]) continue;
            self(self, v, v);
        }
    };

    auto dfs2 = [&](auto &&self, int u, int p) -> void {
        if (G[u].size() == 1) {
            f[u] = a[u];
            return;
        }

        ll minn[2] = {LINF, LINF};
        for (int v : G[u]) {
            if (v == p) continue;
            self(self, v, u);

            if (minn[0] > minn[1]) swap(minn[0], minn[1]);
            minn[1] = min(minn[1], f[v]);
        }

        f[u] = min((ll)a[u], minn[0] + minn[1]);
    };

    auto lca = [&](int u, int v) -> int {
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]]) {
                swap(u, v);
            }
            u = parent[top[u]];
        }
        return depth[u] < depth[v] ? u : v;
    };

    dfs0(dfs0, 1, 0);
    dfs1(dfs1, 1, 1);
    dfs2(dfs2, 1, 0);

    for (int i = 1; i <= n; i++) {
        auto it = find(G[i].begin(), G[i].end(), parent[i]);
        if (it != G[i].end())
            G[i].erase(it);

        sort(G[i].begin(), G[i].end());
    }

    vector<ll> dp(n + 1, LINF);
    dp[1] = a[1];
    auto dfs3 = [&](auto &&self, int u) -> void {
        int m = G[u].size();
        if (m == 0) return;

        vector<ll> pref(m, LINF);
        for (int i = 1; i < m; i++) {
            pref[i] = min(pref[i - 1], f[G[u][i - 1]]);
        }

        ll suff = LINF;
        for (int i = m - 1; i >= 0; i--) {
            dp[G[u][i]] = min(dp[G[u][i]], dp[u] + min(suff, pref[i]));
            suff = min(suff, f[G[u][i]]);
        }

        for (int v : G[u]) {
            self(self, v);
        }
    };

    dfs3(dfs3, 1);

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (depth[x] < depth[y]) {
            cout << -1 << endl;
            continue;
        }

        int u = lca(x, y);
        if (u != y) {
            cout << -1 << endl;
            continue;
        }

        cout << dp[x] - dp[y] << endl;
    }
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