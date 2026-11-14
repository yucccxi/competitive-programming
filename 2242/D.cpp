#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    s = '.' + s, t = '.' + t;

    vector<int> prefs(n + 1);
    vector<int> preft(m + 1);

    for (int i = 1; i <= n; i++) {
        prefs[i] = prefs[i - 1] + (s[i] - '0');
        prefs[i] %= 10;
    }

    for (int i = 1; i <= m; i++) {
        preft[i] = preft[i - 1] + (t[i] - '0');
        preft[i] %= 10;
    }

    if (prefs.back() != preft.back()) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (prefs[i] != preft[j]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            } else {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }

    cout << dp[n][m] << endl;
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