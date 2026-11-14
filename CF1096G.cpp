#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;
const int G   = 3;          // 原根
const int IG  = 332748118;  // 原根的逆元

ll modpow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }

        b >>= 1;
        a = (a * a) % MOD;
    }

    return ans;
}

void ntt(vector<int> &a, int type) {
    int n = a.size();

    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
    }

    for (int i = 0; i < n; i++) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }

    for (int l = 1; l < n; l <<= 1) {
        ll w0 = modpow(type == 1 ? G : IG, (MOD - 1) / (l * 2));
        for (int i = 0; i < n; i += (l << 1)) {
            ll w = 1;
            for (int j = i; j < i + l; j++) {
                ll u = a[j] % MOD;
                ll v = w * a[j + l] % MOD;
                a[j]     = (u + v) % MOD;
                a[j + l] = (u - v + MOD) % MOD;
                w = (w * w0) % MOD;
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    int m = n / 2 * 11;
    int tot = 1;
    while (tot < m) {
        tot <<= 1;
    }

    vector<int> f(tot);
    for (int i = 0; i < k; i++) {
        f[a[i]] = 1;
    }

    ntt(f, 1);

    for (int i = 0; i < tot; i++) {
        f[i] = modpow(f[i], n / 2);
    }

    ntt(f, -1);

    int inv = modpow(tot, MOD - 2);

    for (int i = 0; i < tot; i++) {
        f[i] = (ll)f[i] * inv % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < tot; i++) {
        ans += ((ll)f[i] * f[i]) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}