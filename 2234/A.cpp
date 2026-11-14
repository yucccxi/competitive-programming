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

    sort(a.begin() + 1, a.end(), greater<int>());

    for (int i = 3; i <= n; i++) {
        if (a[i - 1] == 0 || a[i - 2] % a[i - 1] != a[i]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << a[1] << " " << a[2] << endl;
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