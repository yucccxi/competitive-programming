#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    a[2] = min(a[2], a[0] + a[1]);
    cout << a[2] - a[0] << endl;
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