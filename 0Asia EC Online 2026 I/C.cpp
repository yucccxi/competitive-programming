#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ind(n + 1);
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;

        int u; cin >> u;
        for (int j = l + 1; j <= r; j++) {
            int v; cin >> v;
            G[u].push_back(v);
            ++ind[v];
            u = v;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> topo;

    while (pq.size() > 0) {
        int u = pq.top();
        pq.pop();

        topo.push_back(u);

        for (int v : G[u]) {
            if (--ind[v] == 0) {
                pq.push(v);
            }
        }
    }

    if (topo.size() != n) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans(n + 1);

    for (int i = 0; i < n; i++) {
        ans[topo[i]] = i + 1;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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