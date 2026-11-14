#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 2e6 + 5;
const int MOD = 998244353;

ll fac[MAXN + 1], invfac[MAXN + 1];

ll modpow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

ll inv(ll n) {
    return modpow(n, MOD - 2);
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i ++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    invfac[MAXN] = inv(fac[MAXN]);
    for (int i = MAXN; i > 0; i --) {
        invfac[i - 1] = (invfac[i] * i) % MOD;
    }
}

ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

void solve() {
    int n, m, c, a, b;
    cin >> n >> m >> c >> a >> b;
    if (m < n || (m - n) % c != 0) {
        cout << 0 << endl;
        return;
    }

    int k = (m - n) / c;
    ll ans = n * inv(m) % MOD;
    ans = (ans * comb(m, k)) % MOD;
    ans = (ans * modpow(a * inv(b) % MOD, k)) % MOD;
    ans = (ans * modpow((b - a) * inv(b) % MOD, m - k)) % MOD;
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