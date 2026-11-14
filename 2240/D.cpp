#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ll tot = 0;
        if (i - d - 1 >= 0) tot += pref[i - 1] - pref[i - d - 1];
        else                tot += pref[i - 1] + (pref[n] - pref[n - (d - i + 1)]);
        if (i + d <= n)     tot += pref[i + d] - pref[i];
        else                tot += pref[n] - pref[i] + pref[d - (n - i)];

        ll delta = 2LL * d * a[i] - tot;

        if (delta > 0) {
            ans += delta;
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