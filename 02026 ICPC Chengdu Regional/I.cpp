#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void cat() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> b(n + 1);
    vector<bool> marked(n + 1);
    int time = 0;
    auto dfs = [&](auto &&self, int u) -> void {
        marked[u] = true;
        b[u] = ++time;
        for (int v : G[u]) {
            if (marked[v]) continue;
            self(self, v);
        }
        ++time;
    };

    for (int i = 1; i <= n; i++) {
        if (!marked[i]) dfs(dfs, i);
    }

    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

void dog() {
    int n; cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> mp(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        mp[b[i]] = i;
    }

    vector<pair<int, int>> ans;

    stack<int> vert;
    for (int val = 1; val <= 2 * n; ++val) {
        if (mp[val] == 0) {
            assert(vert.size() > 0);
            vert.pop();
            continue;
        }

        if (vert.size() > 0) {
            ans.push_back({vert.top(), mp[val]});   
        }

        vert.push(mp[val]);
    }

    cout << ans.size() << endl;
    for (auto &[u, v] : ans) {
        cout << u << " " << v << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s;
    int t; cin >> t;
    while (t--) {
        if (s == "cat") {
            cat();
        } else {
            dog();
        }
    }

    return 0;
}