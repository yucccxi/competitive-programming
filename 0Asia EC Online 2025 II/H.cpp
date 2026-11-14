#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD  = 998244353;
const int MAXN = 3005;

ll fac[MAXN];

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> T(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    ll ans = 1;

    auto dfs = [&](auto &&self, int u, int p) -> unordered_map<int, int> {
        unordered_map<int, int> all;
        all[0]++;
        for (int v : T[u]) {
            if (v == p) continue;
            unordered_map<int, int> ret = self(self, v, u);
            for (auto &[l0, c0] : ret) {
                for (auto &[l1, c1] : all) {
                    int l = l0 + l1 + 2;
                    ans += (fac[l] - 2 * fac[l - 1] + fac[l - 2] + 2 * MOD) % MOD * ((ll)c0 * c1 % MOD) % MOD;
                    ans %= MOD;
                }
            }
            for (auto &[k, v] : ret) {
                all[k + 1] += v;
            }
        }

        return all;
    };

    dfs(dfs, 1, 0);

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}