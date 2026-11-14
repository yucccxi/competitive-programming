#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

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
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> lsum(n + 1), rsum(n + 2), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        lsum[i] = (lsum[i - 1] + (ll)a[i] * i) % MOD;
        rsum[n - i + 1] = (rsum[n - i + 2] + (ll)a[n - i + 1] * i) % MOD;
        pref[i] = (pref[i - 1] + a[i]) % MOD;
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        int len = min(i, n - i + 1) - 1;
        ll cur = lsum[len] + rsum[n - len + 1];
        cur += (len + 1) * (pref[n - len] - pref[len] + MOD) % MOD;
        cur %= MOD;

        ans += cur * inv(i);
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