#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int MAXN = 5005;

int dp[MAXN][MAXN], stamp[MAXN][MAXN], tsp;

void solve() {
    ll a, b;
    cin >> a >> b;

    ++tsp;

    dp[a][0] = 0;
    stamp[a][0] = tsp;

    for (int i = a; i >= 0; i--) {
        for (int j = 0; j <= a; j++) {
            if (stamp[i][j] != tsp) continue;

            int g = gcd(i, b - j);
            if (i >= g) {
                if (stamp[i - g][j] != tsp) {
                    dp[i - g][j] = dp[i][j] + 1;
                    stamp[i - g][j] = tsp;
                } else {
                    dp[i - g][j] = min(dp[i - g][j], dp[i][j] + 1);
                }
            }

            if (j + g <= a) {
                if (stamp[i][j + g] != tsp) {
                    dp[i][j + g] = dp[i][j] + 1;
                    stamp[i][j + g] = tsp;
                } else {
                    dp[i][j + g] = min(dp[i][j + g], dp[i][j] + 1);
                }
            }
        }
    }

    int ans = 100000000;
    for (int j = 0; j <= a; j++) {
        if (stamp[0][j] != tsp) continue;
        ans = min(ans, dp[0][j] + (j != b));
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