#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e5 + 5;

int n;
vector<int> G[MAXN];

double ans = 0;

void dfs(int u, int p, double prob, int d) {
    int cnt = 0;
    for (int v : G[u]) {
        cnt += (v != p);
    }

    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u, prob / cnt, d + 1);
    }

    if (cnt == 0) {
        ans += prob * d;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0, 1, 0);

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(15);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}