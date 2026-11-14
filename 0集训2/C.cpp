#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<set<int>> from(n + 1), to(n + 1);
    vector<int> parent(n + 1), sz(n + 1);

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int u; cin >> u;
            to[u].insert(i);
            from[i].insert(u);
        }
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    auto find = [&](auto &&self, int u) -> int {
        return u == parent[u] ? u : parent[u] = self(self, parent[u]);
    };

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        if (from[i].size() == 1) {
            q.push({i, *from[i].begin()});
        }
    }

    while (q.size() > 0) {
        auto [u, f] = q.front();
        q.pop();

        int x = find(find, u), y = find(find, f);
        if (find(find, u) == find(find, f)) continue;

        if (to[x].size() > to[y].size()) {
            swap(x, y);
            swap(from[x], from[y]);
        }

        sz[y] += sz[x];
        parent[x] = y;

        for (int v : to[x]) {
            int nxt = find(find, v);
            if (nxt == y) continue;

            to[y].insert(nxt);
            from[nxt].erase(x);
            from[nxt].insert(y);

            if (from[nxt].size() == 1) {
                q.push({nxt, y});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, sz[find(find, i)]);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}