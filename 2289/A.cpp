#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    ll x;
    cin >> x;
    if ((x % 2 == 0) && (x % 4 != 0)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
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