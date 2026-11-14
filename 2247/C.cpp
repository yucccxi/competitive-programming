#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int cnt = 0, sm = 0;
    bool has1 = false;
    bool same0 = false, same1 = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            cnt++;
            sm += a[i];
            if (a[i] == 1) has1 = true;
        } else {
            if (a[i] == 0) same0 = true;
            else           same1 = true;
        }
    }

    if (cnt == 0) {
        cout << 0 << endl;
    } else if (sm & 1) {
        cout << 1 << endl;
    } else if (has1) {
        cout << 2 << endl;
    } else if (same0 && same1) {
        cout << 2 << endl;
    } else {
        cout << -1 << endl;
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