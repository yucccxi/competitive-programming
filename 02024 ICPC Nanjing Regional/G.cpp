#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int query(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int x; cin >> x;
    return x;
}

void answer(int u) {
    cout << "! " << u << endl;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        if (l) {
            G[i].push_back(l);
            G[l].push_back(i);
        }

        if (r) {
            G[i].push_back(r);
            G[r].push_back(i);
        }
    }

    vector<bool> marked(n + 1);
    vector<int> sz(n + 1);
    auto csize = [&](auto &&self, int u, int p) -> void {
        sz[u] = 1;
        for (int v : G[u]) {
            if (v == p || marked[v]) continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
    };

    auto centroid = [&](int u) -> int {
        csize(csize, u, 0);

        int half = sz[u] >> 1;

        int p = 0;
        bool found = false;
        while (!found) {
            found = true;
            for (int v : G[u]) {
                if (v == p || marked[v] || sz[v] <= half) continue;
                found = false;
                p = u;
                u = v;
                break;
            }
        }

        return u;
    };

    int u = 1;
    while (true) {
        u = centroid(u);
        csize(csize, u, 0);

        vector<int> child;
        for (int v : G[u]) {
            if (marked[v]) continue;
            child.push_back(v);
        }

        sort(child.begin(), child.end(), [&](int p, int q) -> bool {
            return sz[p] < sz[q];
        });

        if (child.size() == 0) {
            answer(u);
            break;
        }

        int p, q;
        if (child.size() == 1) {
            int ans = query(u, child[0]);

            if (ans == 0) answer(u);
            else          answer(child[0]);
            break;
        } else if (child.size() == 2) {
            int ans = query(child[0], child[1]);

            if      (ans == 0) marked[u] = true, u = child[0];
            else if (ans == 2) marked[u] = true, u = child[1];
            else {
                answer(u);
                break;
            }
        } else {
            int ans = query(child[1], child[2]);

            if      (ans == 0) marked[u] = true, u = child[1];
            else if (ans == 2) marked[u] = true, u = child[2];
            else marked[child[1]] = true, marked[child[2]] = true;
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