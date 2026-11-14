#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    int N = 1 << n;

    vector<vector<int>> G(N + 1);
    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;

    auto dfs = [&](auto &&self, int u, int p) -> int {
        int sz = 1, f = 0;
        for (int v : G[u]) {
            if (v == p) continue;
            int nsz = self(self, v, u);
            sz += nsz;
            f += nsz >> 1 & 1;
        }

        f &= 1;
        int F = sz >> 1 & 1;
        if (F ^ f) {
            ans ^= u;
        }

        return sz;
    };

    for (int u : G[0]) {
        dfs(dfs, u, 0);
    }

    for (int v = 1; v < N; v++) {
        ans ^= v;
    }

    cout << ans << endl;
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