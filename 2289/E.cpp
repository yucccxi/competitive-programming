#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, d;
    vector<pair<int, int>> all;
    for (int i = 1; i <= n - 1; i++) {
        int l, r;
        cin >> l >> r;
        all.emplace_back(l, r);
    }

    vector<set<int>> rg(2 * n);
    for (int i = 1; i <= n; i++) {
        rg[i].insert(i);
    }

    vector<int> ans(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int r = n + i + 1;
        auto &[u, v] = all[i];

        vector<int> &p = rg[u], &q = rg[v];
        if (p.size() < q.size()) {
            
        }
    }
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