#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = '*' + s + '*';

    int ans = 0;

    int cnt = 0;
    for (char c : s) {
        if (c == '*') {
            ans = max(ans, (cnt + 1) / 2);
            cnt = 0;
        } else {
            cnt++;
        }
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