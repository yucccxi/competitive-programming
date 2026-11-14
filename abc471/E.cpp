#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int MAXN = 2e5 + 5;
constexpr int MOD  = 998244353;

ll fac[MAXN], invfac[MAXN];

ll modpow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i ++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    invfac[MAXN] = modpow(fac[MAXN], MOD - 2);
    for (int i = MAXN; i > 0; i --) {
        invfac[i - 1] = (invfac[i] * i) % MOD;
    }
}

ll comb(ll n, ll k) {
    if (n < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += a[i];
    }

    tot %= MOD;

    ll ans = 0;
    ll t0 = comb(n - 1, k - 1);
    ll t1 = comb(n - 2, k - 2);
    for (int i = 1; i <= n; i++) {
        ll sm = a[i] * t0 % MOD;
        sm  += t1 * (tot - a[i] + MOD) % MOD;
        ans += a[i] * sm % MOD;
    }

    ans %= MOD;

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}