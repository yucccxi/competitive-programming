#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;
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
    string s; cin >> s;
    s = '.' + s;

    int cntb[2] {};
    int cnt[2]  {};

    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            cntb[s[i] - '0']++;
        }

        cnt[s[i] - '0']++;
    }

    if (cnt[0] == 0 || cnt[1] == 0) {
        cout << 1 << endl;
        return;
    }

    ll ans = comb(cnt[0] - 1, cntb[0] - 1) * comb(cnt[1] - 1, cntb[1] - 1) % MOD;
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