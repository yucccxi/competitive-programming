#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return;
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    vector<ll> a(n + 1);
    a[1] = 2;
    a[2] = 4;
    a[3] = 6;

    ll pref = 12;
    for (int i = 4; i <= n; i++) {
        a[i] = pref;
        pref += a[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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