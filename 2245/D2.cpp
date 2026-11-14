#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(2 * n + 1);
    vector<int> din(2 * n + 1);
    for (int i = 1; i <= m; i++) {
        int o, p, q;
        cin >> o >> p >> q;
        if (o == 1) {
            G[q + n].push_back(p);
            G[p + n].push_back(q);
            din[p]++, din[q]++;
        } else if (o == 2) {
            G[q].push_back(p + n);
            G[p].push_back(q + n);
            din[p + n]++, din[q + n]++;
        } else assert(false);
    }

    vector<int> topo(1);

    queue<int> q;
    for (int i = 1; i <= 2 * n; i++) {
        if (din[i] == 0) q.push(i);
    }

    while (q.size() > 0) {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (int v : G[u]) {
            if (--din[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topo.size() != 2 * n + 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<int> idx(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        idx[topo[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << idx[i] - idx[i + n] << " ";
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