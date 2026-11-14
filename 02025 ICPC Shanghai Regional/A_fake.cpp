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
    for (int u = 2; u <= n; u++) {
        int p; cin >> p;
        G[p].push_back(u);
        G[u].push_back(p);
    }

    vector<int> dist(n + 1);
    vector<bool> marked(n + 1);

    int remain = n;

    auto dfs = [&](auto &&self, int u, int p) -> void {
        dist[u] = dist[p] + 1;
        for (int v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
        }
    };

    for (int i = 0; i < 40; i++) {
        for (int u = 1; u <= n; u++) {
            if (!marked[u]) {
                dfs(dfs, u, 0);
                break;
            }
        }

        if (remain == 1) {
            for (int u = 1; u <= n; u++) {
                if (!marked[u]) {
                    answer(u);
                    return;
                }
            }
        }

        int mxd = 0, curv;
        for (int u = 1; u <= n; u++) {
            if (!marked[u] && dist[u] > mxd) {
                mxd = dist[u];
                curv = u;
            }
        }

        int cnt = 1, maxl = 0;

        queue<int> q;
        vector<int> lvl(n + 1, -1);

        q.push(curv);

        dist[curv] = 0;
        lvl[curv] = 0;

        while (q.size() > 0) {
            int u = q.front();
            q.pop();

            for (int v : G[u]) {
                if (lvl[v] != -1) continue;
                lvl[v] = lvl[u] + 1;
                dist[v] = dist[u] + 1;

                q.push(v);

                if (!marked[v]) {
                    ++cnt;
                    if (lvl[v] > maxl && 2 * cnt <= remain) {
                        maxl = lvl[v] - 1;
                    }
                }
            }
        }

        bool b = query(curv, maxl);
        for (int u = 1; u <= n; u++) {
            if (marked[u]) continue;
            if ((lvl[u] <= maxl) ^ b) {
                marked[u] = true;
                // cout << u << " ";
                --remain;
            }
        }

        // cout << endl;
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