#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n & 1) {
        cout << "NO" << endl;
        return;
    }

    int lk = 0, rk = INF;

    for (int i = 1; i <= n; i += 2) {
        if (a[i] <= a[i + 1]) {
            cout << "NO" << endl;
            return;
        }

        lk = max(lk, a[i + 1]);
        rk = min(rk, a[i]);
    }

    if (rk - lk > 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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