#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 1e9 + 7;

ll modpow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
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

    vector<pair<int, int>> segs;
    segs.push_back({a[1], 0});
    for (int i = 1; i <= n; i++) {
        if (a[i] == segs.back().first) {
            segs.back().second++;
        } else {
            segs.push_back({a[i], 1});
        }
    }

    ll ans = 1;

    for (auto &[v, c] : segs) {
        ans *= modpow(2, c - 1);
        ans %= MOD;
    }

    const ll INV2 = inv(2);

    if (segs[0].first == -1) {
        ll t = ans;
        for (int i = 2; i < segs.size(); i++) {
            if (segs[i - 1].first == -1 || segs[i].first - segs[i - 1].first != 1) continue;
            ans = (ans + t) % MOD;
        }
    }

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