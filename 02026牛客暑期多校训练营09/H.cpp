#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    int cnt = 0, gmax = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cnt += x & 1;
        gmax = max(gmax, x);
    }

    cout << (gmax + (cnt & 1)) / 2 << endl;
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