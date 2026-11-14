#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 105    ;
const int LCM  = 2520   ;
const int MOD  = 1e9 + 7;

int n;
ll k;
int a[MAXN];

ll dp[LCM * MAXN + 5];

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

ll inv(ll x) {
    return modpow(x, MOD - 2);
}

void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= LCM * (n + 2); i++) {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= LCM * (n + 2); j++) {
            if (j < a[i]) continue;
            dp[j] += dp[j - a[i]];
            dp[j] %= MOD;
        }
    }

    ll q = k / LCM, r = k % LCM;
    q %= MOD;

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll lx = 1;
        for (int j = 0; j <= n; j++) {
            if (i == j) continue;
            lx *= (q - j + MOD) * inv(i - j + MOD) % MOD;
            lx %= MOD;
        }

        ans = (ans + dp[r + i * LCM] * lx % MOD) % MOD;
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