#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll LINF = 1e18;
const int MAXN = 1e6 + 5;

int n;
int a[MAXN];
vector<int> G[MAXN];

ll dp[MAXN][4], tmp[4];

void dfs(int u, int p) {
    dp[u][0] = 0, dp[u][1] = a[u], dp[u][2] = -a[u], dp[u][3] = 0;
    for (int v : G[u]) {
        if (v == p) continue;

        dfs(v, u);
        for (int i = 0; i < 4; i++) tmp[i] = -LINF;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j == 3) tmp[i] = max(tmp[i], dp[u][i] + dp[v][j]); // 断开
                if ((i & j) == 0) { // 连接
                    tmp[i | j] = max(tmp[i | j], dp[u][i] + dp[v][j]);
                }
            }
        }

        for (int i = 0; i < 4; i++) dp[u][i] = tmp[i];
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    cout << dp[1][3] << endl;
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