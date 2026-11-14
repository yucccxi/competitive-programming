#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct coord {
    int x, y;
};

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

ll fac[MAXN], invfac[MAXN];

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

ll inv(ll x) { return modpow(x, MOD - 2); }

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    invfac[MAXN - 1] = inv(fac[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

ll comb(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<coord>> pos(n * m + 1);

    const int B = sqrt(n * m) + 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pos[a[i][j]].push_back({i, j});
        }
    }

    ll ans = 0;

    for (int v = 1; v <= n * m; v++) {
        int sz = pos[v].size();
        if (sz <= B) {
            vector<int> dp(sz);
            for (int i = 0; i < sz; i++) {
                ll cur = comb(pos[v][i].x + pos[v][i].y - 2, pos[v][i].x - 1);
                for (int j = 0; j < i; j++) {
                    if (pos[v][j].x <= pos[v][i].x && pos[v][j].y <= pos[v][i].y) {
                        cur -= dp[j] * comb(
                            pos[v][i].x - pos[v][j].x + pos[v][i].y - pos[v][j].y, 
                            pos[v][i].x - pos[v][j].x
                        ) % MOD;
                        cur = (cur + MOD) % MOD;
                    }
                }
                dp[i] = cur;
                ans += cur * comb(
                                n - pos[v][i].x + m - pos[v][i].y,
                                n - pos[v][i].x
                            ) % MOD;
                ans %= MOD;
            }
        } else {
            vector<vector<int>> dp(n + 1, vector<int>(m + 1));
            dp[1][1] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i - 1][j] != v) dp[i][j] += dp[i - 1][j];
                    if (a[i][j - 1] != v) dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= MOD;
                }
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] == v) {
                        int p = n - i + 1, q = m - j + 1;
                        ans += dp[i][j] * comb(p + q - 2, p - 1) % MOD;
                        ans %= MOD;
                    }
                }
            }
            ans %= MOD;
        }
    }

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