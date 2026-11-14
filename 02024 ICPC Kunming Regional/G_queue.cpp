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

    queue<pair<int, int>> q;

    dp[a][0] = 0;
    stamp[a][0] = tsp;
    q.emplace(a, 0);

    int ans = INT_MAX;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (i == 0) {
            ans = min(ans, dp[i][j] + (j != b));
            continue;
        }

        int g = gcd((ll)i, b - j);

        auto update = [&](int x, int y) {
            if (stamp[x][y] == tsp) return;

            stamp[x][y] = tsp;
            dp[x][y] = dp[i][j] + 1;
            q.emplace(x, y);
        };

        if (i >= g) {
            update(i - g, j);
        }

        if (b - j > 0 && j + g <= a) {
            update(i, j + g);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}