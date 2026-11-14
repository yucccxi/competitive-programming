#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int xr = 0;
    for (int i = 1; i <= n; i++) {
        xr ^= a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if ((xr ^ a[i]) < a[i]) ans++;
    }

    if (xr == 0) ans++;

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