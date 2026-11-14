#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> xs(n + 1), ys(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        xs[x]++, ys[y]++;
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, n - xs[i]);
        ans = min(ans, n - ys[i]);
    }

    cout << ans << endl;
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