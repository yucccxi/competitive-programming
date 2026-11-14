#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

ll f[105][105][5512];

void precompute() {
    f[0][0][0] = 1;
    for (int L = 1; L <= 100; L++) {
        for (int K = 0; K <= L; K++) {
            for (int S = 0; S <= 5511; S++) {
                f[L][K][S] += f[L - 1][K][S];
                if (K > 0 && S >= L)
                    f[L][K][S] += f[L - 1][K - 1][S - L];
                f[L][K][S] %= MOD;
            }
        }
    }
}

ll modpow(ll a, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(m + 1), v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> p[i] >> v[i];
    }

    p[0] = 1, v[0] = 0;

    vector<ll> dp(105);
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        vector<ll> ndp(105);

        int len = p[i] - p[i - 1];

        for (int u = 0; u <= p[i - 1]; u++) {
            int diff = v[i] - v[i - 1] - u * len;
            for (int k = 0; k <= len; k++) {
                int diff = v[i] - v[i - 1] - u * len;
                if (diff >= 0) {
                    ndp[u + k] += dp[u] * f[len][k][diff];
                    ndp[u + k] %= MOD;
                }
            }
        }
        swap(dp, ndp);
    }

    ll ans = 0;
    for (int i = 0; i <= 100; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    ans = (ans * modpow(2, n - p.back())) % MOD;

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