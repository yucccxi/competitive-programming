#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e3 + 5;

int w, b;
double dp[MAXN][MAXN];

double ans = 0;

void solve() {
    cin >> w >> b;

    dp[0][b] = 1.0;

    for (int i = 1; i <= (w + b) / 3 + 1; ++i) {
        int pre_tot = w + b - 3 * (i - 1);

        if (pre_tot < 3) break;

        int tot = pre_tot - 3;

        for (int j = 0; j <= b; ++j) {
            int k = tot - j; // white
            if (k < 0 || k > w) continue;

            // 情况 1: 上一状态是 (k, j+3) 公主抽黑 龙抽黑 跳出去白
            if (j + 2 <= b && k + 1 <= w) {
                int pw = k + 1;
                int pb = j + 2;
                int all = pw + pb;

                dp[i][j] += dp[i - 1][j + 2]
                          * pb / all
                          * (pb - 1) / (all - 1)
                          * pw / (all - 2);
            }

            // 情况 2: 上一状态是 (k, j+3) 公主抽黑 龙抽黑 跳出去黑
            if (j + 3 <= b) {
                int pw = k;
                int pb = j + 3;
                int all = pw + pb;

                dp[i][j] += dp[i - 1][j + 3]
                          * pb / all
                          * (pb - 1) / (all - 1)
                          * (pb - 2) / (all - 2);
            }
        }
    }

    for (int i = 0; ; ++i) {
        int tot = w + b - 3 * i;
        if (tot <= 0) break;

        for (int j = 0; j <= b; ++j) {
            int white = tot - j;
            if (white <= 0 || white > w) continue;
            ans += dp[i][j] * white / tot;
        }
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