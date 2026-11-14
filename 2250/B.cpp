#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    if (m > n - 2) {
        cout << -1 << endl;
        return;
    }

    int u = m / 2, v = (m + 1) / 2;

    string ans;
    ans += '0';
    for (int i = 1; i <= u; i++) ans += "0";
    ans += '1';
    for (int i = 1; i <= v; i++) ans += "1";

    bool b = 0;
    for (int i = 1; i <= n - (u + v + 2); i++) {
        ans += '0' + b;
        b ^= 1;
    }

    cout << ans << endl;
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