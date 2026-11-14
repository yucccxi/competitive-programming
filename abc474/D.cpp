#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    bool f = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            f = true;
            break;
        }
    }

    if (!f) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;

    const ll F = 1e18;

    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            cout << F << " ";
        } else {
            cout << 1 << " ";
        }
    }
    cout << endl;
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