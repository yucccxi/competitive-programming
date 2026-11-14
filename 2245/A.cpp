#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = '.' + s;
    if (k > n / 2) {
        cout << -1 << endl;
        return;
    }

    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        cnt += (s[i] == 'L');
    }

    for (int i = n - k + 1; i <= n; i++) {
        cnt += (s[i] == 'R');
    }

    cout << cnt << endl;
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