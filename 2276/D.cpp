#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> marked(n + 1, false);
    bool hasCircle = false;
    int cnt = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        ++cnt;
        marked[u] = true;
        for (int v : G[u]) {
            if (marked[v]) {
                if (v != p) {
                    hasCircle = true;
                }
                continue;
            }

            self(self, v, u);
        }
    };

    bool ok = false;
    vector<int> all;

    for (int u = 1; u <= n; u++) {
        if (!marked[u]) {
            hasCircle = false;
            cnt = 0;

            dfs(dfs, u, 0);

            if (cnt == 1) {
                cout << "Brain Melt" << endl;
                return;
            }

            if (hasCircle) {
                ok = true;
            }
        }
    }

    if (hasCircle || ok) {
        cout << "Many" << endl;
        return;
    }

    marked.assign(n + 1, false);
    auto get = [&](auto &&self, int u, int p, vector<int> &vec) -> void {
        marked[u] = true;
        vec.push_back(u);
        for (int v : G[u]) {
            if (marked[v]) continue;
            self(self, v, u, vec);
        }
    };

    int ccnt = 0;
    int two = 0;

    for (int u = 1; u <= n; u++) {
        if (marked[u]) continue;

        vector<int> vec;
        get(get, u, 0, vec);

        if (vec.size() == 2) {
            ++two;
            continue;
        }

        int leaf = 0, center = 0;

        for (int v : vec) {
            if (G[v].size() == 1) ++leaf;
            else if (G[v].size() == vec.size() - 1) ++center;
            else {
                cout << "Many" << endl;
                return;
            }
        }

        if (leaf == vec.size() - 1 && center == 1) {
            ++two;
            continue;
        }

        ++ccnt;
    }

    if (ccnt > 0) {
        cout << "Many" << endl;
        return;
    }

    if (two == 1) {
        cout << 2 << endl;
    } else {
        cout << "Many" << endl;
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