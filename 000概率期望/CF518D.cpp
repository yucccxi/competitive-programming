#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 2e3 + 5;

int n, t;
double p;

double dp[MAXN][MAXN], ans;

void solve() {
    cin >> n >> p >> t;
    
    dp[0][0] = 1;
    for (int i = 1; i <= t; i++) {
        int ub = min(i, n);
        for (int j = 0; j <= ub; j++) {
            if (j > 0)  dp[i][j] += p * dp[i - 1][j - 1];
            if (j < ub) dp[i][j] += (1 - p) * dp[i - 1][j];
            else        dp[i][j] += dp[i - 1][j];
        }
    }

    for (int i = 0; i <= min(t, n); i++) {
        ans += dp[t][i] * i;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}