#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

#define int long long

const int MOD  = 998244353;
const int G   = 3;          // 原根
const int IG  = 332748118;  // 原根的逆元
const int MAXN = 1e6 + 5;

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

ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

void solve() {
    int n; cin >> n;

    int N = n / 3;

    int u = 2 * N + 1;
    int tot = 1;
    while (tot < u) tot <<= 1;

    vector<int> P(tot), Q(tot);
    for (int i = 0; i <= N; i++) {
        P[i] = (i & 1) ? MOD - invfac[i] : invfac[i];
    }

    for (int i = N; i >= 0; i--) {
        Q[i] = fac[N - i] * comb(n - 2 * (N - i), N - i) % MOD * modpow(26, n - 3 * (N - i)) % MOD;
    }

    ntt(P, 1);
    ntt(Q, 1);

    vector<int> R(tot);

    for (int i = 0; i < tot; i++) {
        R[i] = (ll)P[i] * Q[i] % MOD;
    }

    ntt(R, -1);

    const ll INV_TOT = modpow(tot, MOD - 2);

    for (int i = 0; i < tot; i++) {
        R[i] = R[i] * INV_TOT % MOD;
    }

    for (int i = 0; i <= n; i++) {
        if (i > N) {
            cout << 0 << " ";
        } else {
            cout << R[N - i] * invfac[i] % MOD << " ";
        }
    }

    cout << endl;
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