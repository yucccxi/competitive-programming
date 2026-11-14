#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += a[i] / x;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (tot - a[i] / x) * y + a[i]);
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