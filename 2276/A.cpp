#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int dp[105][105];

void solve() {
    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int p = 2; p <= i; p++) {
                for (int q = 1; q < p && q <= j; q++) {
                    if (dp[i - p][j - q] != -1) {
                        dp[i][j] = max(dp[i][j], dp[i - p][j - q] + 1);
                    }
                }
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}