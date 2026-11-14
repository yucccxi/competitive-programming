#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll  LINF = 1e18   ;
const int MAXN = 5e5 + 5;
const int MOD  = 1e9 + 7;

int n;
ll a[MAXN];

int sz[MAXN], ln[MAXN], rn[MAXN];
bool valid;

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

int build(int l, int r) {
    if (!valid) return -1;

    if (a[l] % (sz[ln[l]] + 1) != 0) {
        valid = false;
        return -1;
    }

    ll szr = a[l] / (sz[ln[l]] + 1) - 1;
    if (l + szr > r) {
        valid = false;
        return -1;
    }

    sz[l] = sz[ln[l]] + szr + 1;

    if (szr > 0) rn[l] = build(l + 1, l + szr);

    if (l + szr + 1 <= r) {
        ln[l + szr + 1] = l;
    }

    if (l + szr + 1 > r) {
        return l;
    }

    return build(l + szr + 1, r);
}

ll dfs(int u) {
    if (u == 0) return 1;
    return dfs(ln[u]) * dfs(rn[u]) % MOD * comb(sz[u] - 1, sz[ln[u]]) % MOD;
}

void reset(int n) {
    valid = true;
    for (int i = 1; i <= n; i++) {
        sz[i] = 0;
        ln[i] = 0;
        rn[i] = 0;
    }
}

void solve() {
    cin >> n;

    reset(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int r = build(1, n);

    if (!valid) {
        cout << 0 << endl;
        return;
    }

    cout << dfs(r) << endl;
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