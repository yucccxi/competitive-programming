#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

ll calc(int l, int r, int h) {
    ll ans = 0;
    int ml = min(h, l);
    int mr = min(h, r);
    int d  = min(l + 1, max(0, h - mr));
    ans += (ll)d * (mr + 1);

    int lo = h - ml + 1, hi = mr + 1;
    if (lo <= hi) {
        ans += (ll)(lo + hi) * (hi - lo + 1) / 2;
    }

    ans -= 1;

    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            ll ans = 0;
            ans += calc(j, m - j, i);
            ans += calc(j, m - j, n - i);
            ans += calc(i, n - i, j);
            ans += calc(i, n - i, m - j);

            ans -= min(i, j);
            ans -= min(n - i, j);
            ans -= min(i, m - j);
            ans -= min(n - i, m - j);

            cout << ans << " ";
        }
        cout << endl;
    }
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