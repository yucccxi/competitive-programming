#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> best(n * m + 1);
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<int>> ans(n + 2, vector<int>(m + 2));

    auto plus = [&](int x1, int y1, int x2, int y2) -> void {
        ans[x1][y1]++;
        ans[x1][y2 + 1]--;
        ans[x2 + 1][y1]--;
        ans[x2 + 1][y2 + 1]++;
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (best[g[i][j]].size() == 0) {
                continue;
            }

            for (auto &[u, v] : best[g[i][j]]) {
                if (v < j) plus(u, v, i, j);
            }
        }

        for (int j = 1; j <= m; j++) {
            if (best[g[i][j]].size() == 0 || j < best[g[i][j]].back().second) {
                best[g[i][j]].push_back({i, j});
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i][j] += ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            cout << (ans[i][j] > 0);
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}