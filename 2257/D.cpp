#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct Q {
    ll x, y;
};

void solve() {
    ll s;
    int q;
    cin >> s >> q;

    vector<ll> f;
    for (ll i = 1; i * i <= s; i++) {
        if (s % i == 0) {
            f.push_back(i);
            if (i * i != s) {
                f.push_back(s / i);
            }
        }
    }

    sort(f.begin(), f.end());

    vector<ll> pref(f.size());

    ll prev = 0;
    for (int i = 0; i < f.size(); i++) {
        ll x = f[i], y = s / x;
        ll cur = (x - prev) * y;
        pref[i] += cur;
        if (i > 0) pref[i] += pref[i - 1];
        prev = x;
    }

    while (q--) {
        ll x, y;
        cin >> x >> y;
        int l = 0, r = f.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (s / f[mid] >= y) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // r

        ll ans = 0;
        if (r >= 0) ans += min(x, f[r]) * y;
        
        if (f[r] < x) {
            int lb = upper_bound(f.begin(), f.end(), x) - f.begin() - 1;
            ans += pref[lb] - (r >= 0 ? pref[r] : 0);
            if (lb < f.size() - 1) {
                ans += (x - f[lb]) * (s / f[lb + 1]);
            }
        }

        cout << ans << endl;
    }
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