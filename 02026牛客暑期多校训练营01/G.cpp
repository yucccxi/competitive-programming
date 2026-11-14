#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    cout << fixed << setprecision(9);
    
    int n; cin >> n;

    cout << 2 * n << endl;

    double d = 0.01001;
    for (int i = 0; i < n; i++) {
        cout << 0.0 << " " << (i / 10) * d << " " << (i % 10) * d << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << 1.0 << " " << (i / 10) * d << " " << (i % 10) * d << endl;
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