#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 2e4 + 5;
const int MAXM = 25;
const int MAXS = (1 << 20);

int n, m;
int d[MAXN][MAXM];
string s[MAXN];

int accept[MAXN];
ll cost[MAXM][MAXS], dp[MAXS];

void solve() {

    memset(dp, 0x3f, sizeof(dp));

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
        cin >> s[i];

        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                accept[i] |= (1 << j);
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cost[j][accept[i]] += d[i][j];
        }

        for (int i = 0; i < m; i++) {
            for (int mask = 0; mask < (1 << m); ++mask) {
                if (mask >> i & 1) continue;
                cost[j][mask] += cost[j][mask | (1 << i)]; 
            }
        }
    }

    dp[0] = 0;

    for (int mask = 0; mask < (1 << m); ++mask) {
        for (int j = 0; j < m; j++) {
            if (mask >> j & 1) continue;
            dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[j][mask]);
        }
    }

    cout << dp[(1 << m) - 1] << endl;
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