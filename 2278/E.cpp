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

    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
        if (i & 1) b[i] = -b[i];
    }

    sort(b.begin() + 1, b.end());

    ll ans = 0;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        ans -= b[i];
    }

    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        ans += b[i];
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