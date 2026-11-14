#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD   = 1e9 + 7;
const int MAXV  = 5e5 + 5;
const int MAXN  = 1e5 + 5;
const int MAXLG = 20;

int n, x;
int a[MAXN], spf[MAXV];

vector<int> primes;

void sieve() {
    for (int i = 1; i < MAXV; i ++) spf[i] = i;
    for (int i = 2; i < MAXV; i ++) {
        if (spf[i] == i) {
            for (ll j = (ll)i * i; j < MAXV; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    for (int i = 2; i < MAXV; i++) {
        if (spf[i] == i) {
            primes.push_back(i);
        }
    }
}

ll compute(ll p, int c) {
    vector<vector<ll>> dp(20, vector<ll>(c + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<vector<ll>> ndp(20, vector<ll>(c + 1));
        int b = 0, v = a[i];
        while (v % p == 0) {
            v /= p;
            ++b;
        }

        vector<vector<ll>> diff(20, vector<ll>(c + 1));

        for (int m = 0; m < 20; m++) {
            int r = min(m, b);
            for (int s = 0; s <= c; s++) {
                if (r < b && s >= m) {
                    diff[r + 1][s] += dp[m][s - m];
                    diff[b + 1][s] -= dp[m][s - m];

                    diff[r + 1][s] = (diff[r + 1][s] % MOD + MOD) % MOD;
                    diff[b + 1][s] = (diff[b + 1][s] % MOD + MOD) % MOD;
                }
            }
        }

        for (int j = 0; j <= c; j++) {
            for (int i = 1; i < 20; i++) {
                diff[i][j] += diff[i - 1][j];
                diff[i][j] = (diff[i][j] % MOD + MOD) % MOD;
            }
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 1; j <= c; j++) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD + MOD;
                dp[i][j] %= MOD;
            }
        }

        for (int m = 0; m < 20; m++) {
            int r = min(m, b);
            for (int s = 0; s <= c; s++) {
                int l = s - r - 1;
                ndp[m][s] += dp[m][s] - (l < 0 ? 0 : dp[m][l]);
                ndp[m][s] = (ndp[m][s] % MOD + MOD) % MOD;
            }
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j <= c; j++) {
                ndp[i][j] += diff[i][j];
                ndp[i][j] = (ndp[i][j] % MOD + MOD) % MOD;
            }
        }

        swap(dp, ndp);
    }

    ll ans = 0;

    for (int i = 0; i < 20; i++) {
        ans += dp[i][c];
    }

    ans %= MOD;

    return ans;
}

void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt, cx;
    for (int i = 1; i <= n; i++) {
        int v = a[i];
        while (v > 1) {
            cnt[spf[v]]++;
            v /= spf[v];
        }
    }

    {
        int v = x;
        while (v > 1) {
            int c = 0, p = spf[v];
            while (spf[v] == p) {
                v /= p;
                c++;
            }
            cx[p] = c;
        }
    }

    ll ans = 1;

    for (auto [p, sum] : cnt) {
        if (!cx.count(p)) {
            ans = ans * (sum + 1) % MOD;
        } else {
            ans = ans * compute(p, cx[p]) % MOD;
        }
    }

    for (auto [p, c] : cx) {
        if (!cnt.count(p)) {
            ans = 0;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    sieve();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}