#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 1e9 + 7;
const int MAXN = 205;

ll dp[MAXN][MAXN][MAXN];

void solve() {
    int n, m;
    cin >> n >> m;
    string a; cin >> a;
    a = '.' + a;

    if (m & 1) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                dp[i][j][k] = 0;
            }
        }
    }

    dp[0][0][0] = 1;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= n; k++) {
                if (j + 1 <= m) {
                    int nk = k + (k + 1 <= n && a[k + 1] == '(');
                    dp[i + 1][j + 1][nk] += dp[i][j][k];
                    dp[i + 1][j + 1][nk] %= MOD;
                }

                if (j > 0) {
                    int nk = k + (k + 1 <= n && a[k + 1] == ')');
                    dp[i + 1][j - 1][nk] += dp[i][j][k];
                    dp[i + 1][j - 1][nk] %= MOD;
                }
            }
        }
    }

    cout << dp[m][0][n] << endl;
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