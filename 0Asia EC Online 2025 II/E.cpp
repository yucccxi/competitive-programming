#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

struct mat {
    ll a[2][2];

    mat operator*(const mat &o) const {
        mat ret;

        ret.a[0][0] = 0;
        ret.a[0][1] = 0;
        ret.a[1][0] = 0;
        ret.a[1][1] = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ret.a[i][j] += a[i][k] * o.a[k][j];
                    ret.a[i][j] %= MOD;
                }
            }
        }

        return ret;
    }
};

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

mat matpow(mat a, ll n) {
    mat ans;
    ans.a[0][0] = 1;
    ans.a[0][1] = 0;
    ans.a[1][0] = 0;
    ans.a[1][1] = 1;

    while (n > 0) {
        if (n & 1) {
            ans = ans * a;
        }

        a = a * a;
        n >>= 1;
    }

    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll M = modpow(2, m);

    mat base;
    base.a[0][0] = ((-M + 1) % MOD + MOD) % MOD;
    base.a[0][1] = 1;
    base.a[1][0] = 0;
    base.a[1][1] = (M - 1) * (M - 1) % MOD;

    mat trans;
    ll dp0;

    if (n & 1) { dp0 = 1; trans = matpow(base, (n - 1) / 2); }
    else       { dp0 = 0; trans = matpow(base, (n - 2) / 2); }

    ll ans = trans.a[0][0] * dp0 % MOD + trans.a[0][1] * M % MOD * modpow(M - 1, (n & 1) ? 1 : 2) % MOD;
    ans %= MOD;

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