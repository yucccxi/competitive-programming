#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 5e5 + 5;
const int MOD  = 1e9 + 7;

ll fac[MAXN], invfac[MAXN];

ll modpow(ll a, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % MOD;
        }

        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    invfac[MAXN - 1] = modpow(fac[MAXN - 1], MOD - 2);

    for (int i = MAXN - 2; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

ll comb(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

int n;
ll a[MAXN];

ll solve0(int l, int r) {
    if (l > r) return 1;

    int tl = l, tr = r;
    int pos = -1;
    while (tl <= tr) {
        if ((ll)(tl - l + 1) * (r - tl + 1) == a[tl]) {
            pos = tl;
            break;
        }

        if ((ll)(tr - l + 1) * (r - tr + 1) == a[tr]) {
            pos = tr;
            break;
        }

        ++tl, --tr;
    }

    if (pos == -1) return 0;

    ll ansl = solve0(l, pos - 1);
    if (ansl == 0) return 0;

    ll ansr = solve0(pos + 1, r);
    if (ansr == 0) return 0;

    ll ans = (ansl * ansr) % MOD * comb(r - l, pos - l) % MOD;
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << solve0(1, n) << endl;
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