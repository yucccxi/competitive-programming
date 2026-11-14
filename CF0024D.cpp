#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int MAXN = 1e3 + 5;
constexpr double EPS = 1e-6;

int n, m, px, py;
double dp[MAXN][MAXN];
double mat[MAXN][MAXN];

void solve() {
    cin >> n >> m >> px >> py;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (m == 1) {
                mat[j][j] = 1;
                mat[j][m + 1] = 2 + dp[i + 1][j];
            } else {
                if (j == 1) {
                    mat[j][j + 1] = -1;
                    mat[j][j] = 2;
                    mat[j][m + 1] = 3 + dp[i + 1][j];
                } else if (j == m) {
                    mat[j][j - 1] = -1;
                    mat[j][j] = 2;
                    mat[j][m + 1] = 3 + dp[i + 1][j];
                } else {
                    mat[j][j - 1] = -1;
                    mat[j][j + 1] = -1;
                    mat[j][j] = 3;
                    mat[j][m + 1] = 4 + dp[i + 1][j];
                }
            }
        }

        for (int j = 1; j <= m - 1; j++) {
            double ratio = mat[j + 1][j] / mat[j][j];
            mat[j + 1][j]     -= ratio * mat[j][j];
            mat[j + 1][j + 1] -= ratio * mat[j][j + 1];
            mat[j + 1][m + 1] -= ratio * mat[j][m + 1];
        }

        dp[i][m] = mat[m][m + 1] / mat[m][m];

        for (int j = m - 1; j >= 1; j--) {
            dp[i][j] = (mat[j][m + 1] - mat[j][j + 1] * dp[i][j + 1]) / mat[j][j];
        }

        for (int j = 1; j <= m; j++) {
            mat[j][j] = 0;
            if (j > 1) mat[j][j - 1] = 0;
            if (j < m) mat[j][j + 1] = 0;
            mat[j][m + 1] = 0;
        }
    }

    cout << dp[px][py] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(10);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}