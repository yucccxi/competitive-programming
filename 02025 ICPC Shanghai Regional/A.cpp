#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int query(int u, int k) {
    cout << "? " << u << " " << k << endl;
    int x; cin >> x;
    return x;
}

void answer(int u) {
    cout << "! " << u << endl;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> G(n + 1);
    vector<int> parent(n + 1);
    for (int u = 2; u <= n; u++) {
        int p; cin >> p;
        parent[u] = p;
        G[p].push_back(u);
        G[u].push_back(p);
    }

    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        bool b = query(1, mid);
        
        if (b) r = mid - 1;
        else   l = mid + 1;
    }

    // l

    // cout << "l = " << l << endl;

    vector<int> depth(n + 1), sz(n + 1);
    vector<bool> marked(n + 1);
    auto cdepth = [&](auto &&self, int u, int p) -> void {
        for (int v : G[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            self(self, v, u);
        }
    }; cdepth(cdepth, 1, 0);

    auto csize = [&](auto &&self, int u, int p) -> void {
        sz[u] = (depth[u] == l);
        for (int v : G[u]) {
            if (v == p || marked[v]) continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
    };

    set<int> cand;
    for (int u = 1; u <= n; u++) {
        if (depth[u] == l) {
            cand.insert(u);
        }
    }

    while (cand.size() > 1) {
        fill(sz.begin(), sz.end(), 0);
        csize(csize, 1, 0);

        int m = cand.size();
        int target = -1;
        for (int u = 1; u <= n; u++) {
            if (depth[u] <= l && 3 * sz[u] >= m && 3 * sz[u] <= 2 * m) {
                target = u;
                break;
            }
        }

        assert(target != -1);

        bool b = query(target, l - depth[target]);

        {

            set<int> all;

            auto ___ = [&](auto &&self, int u, int p) -> void {
                if (depth[u] == l && !marked[u]) all.insert(u);
                for (int v : G[u]) {
                    if (v == p) continue;
                    self(self, v, u);
                }
            };

            ___(___, target, parent[target]);

            if (!b) {
                for (int x : all) {
                    marked[x] = true;
                    cand.erase(x);
                }
            } else {
                swap(cand, all);

                for (int u = 1; u <= n; u++) {
                    if (depth[u] == l && !cand.count(u)) {
                        marked[u] = true;
                    }
                }
            }
        }
    }

    answer(*cand.begin());
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