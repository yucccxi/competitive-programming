#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
    }

    bool ok = false;
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] > 1) {
            ok = true;
            break;
        }
    }

    if (ok) {
        cout << total - 1 << endl;
        return;
    }

    if (a[1] == 1 && a[n] == 1) {
        cout << -1 << endl;
        return;
    }

    cout << a[1] + a[n] - 1 << endl;
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