#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e6;

const int MOD  = 998244353;
const int G    = 3;          // 原根
const int IG   = 332748118;  // 原根的逆元

ll fac[MAXN + 5], invfac[MAXN + 5];

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

ll comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int q; cin >> q;
    vector<int> Q(q);
    for (int &x : Q) cin >> x;

    vector<int> ans(q);

    for (int L : b) {
        vector<int> freq(L);
        for (int x : a) {
            if (x >= L) continue;
            freq[x]++;
        }

        int N0 = 0, N1 = 0;
        for (int i = 0; i < L; i++) {
            if (freq[i] == 1) N0++;
            if (freq[i] >  1) N1++;
        }

        int tot = 1;
        while (tot <= N0 + 2 * N1) tot <<= 1;

        const int INV = modpow(tot, MOD - 2);

        vector<int> f(tot), g(tot), h(tot);
        for (int i = 0; i <= N0; i++) {
            f[i] = comb(N0, i) * modpow(2, i) % MOD;
        }

        for (int i = 0; i <= 2 * N1; i++) {
            g[i] = comb(2 * N1, i);
        }

        ntt(f, 1);
        ntt(g, 1);

        for (int i = 0; i < tot; i++) {
            h[i] = (ll)f[i] * g[i] % MOD;
        }

        ntt(h, -1);

        for (int i = 0; i < tot; i++) {
            h[i] = (ll)h[i] * INV % MOD;
        }

        for (int i = 0; i < q; i++) {
            int X = Q[i];
            int w = X / 2 - L - 1;
            if (w >= 0 && w < tot) {
                ans[i] = (ans[i] + h[w]) % MOD;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
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