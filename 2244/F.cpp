#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        G[p].push_back(i);
        G[i].push_back(p);
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool ok = true;

    auto dfs = [&](auto &&self, int u, int p) -> pair<int, int> {
        if (!ok) return {};

        if (a[u] > 0) return {a[u], a[u]};

        vector<pair<int, int>> all;
        for (int v : G[u]) {
            if (v == p) continue;
            all.push_back(self(self, v, u));
        }

        int mni = 0;
        for (int i = 0; i < all.size(); i++) {
            if (all[i] < all[mni]) {
                mni = i;
            }
        }

        int tot = all.size();

        for (int i = 0; i < tot - 1; i++) {
            int u = (mni + i    ) % tot;
            int v = (mni + i + 1) % tot;
            if (all[u].second > all[v].first) {
                ok = false;
                return {};
            }
        }

        return {all[mni].first, all[(mni + tot - 1) % tot].second};
    };

    dfs(dfs, 1, 0);

    cout << (ok ? "YES" : "NO") << endl;
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