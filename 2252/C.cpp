#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll INF = 9e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    ll ans = m;
    priority_queue<int, vector<int>, greater<int>> pq;
    ll tot = 0, prev = INF;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            pq.push(a[i][j]);
            tot += a[i][j];
        }

        while (pq.size() > ans) {
            tot -= pq.top();
            pq.pop();
        }

        if (tot >= v[i]) {
            while (!pq.empty() && tot - pq.top() >= v[i]) {
                tot -= pq.top();
                pq.pop();
            }
            ans = min(ans, (ll)pq.size());
        }
    }

    cout << ans << endl;
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