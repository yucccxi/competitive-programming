#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> T(n + 1);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        T[i].push_back(p);
        T[p].push_back(i);
    }

    auto dfs = [&](auto &&self, int u, int p) -> multiset<int> {
        multiset<int> all;
        for (int v : T[u]) {
            if (v == p) continue;
            multiset<int> current = self(self, v, u);
            
            if (current.size() > all.size()) {
                swap(current, all);
            }
            
            for (int x : current) {
                all.insert(x);
            }
        }

        auto it = all.begin();
        if (it != all.end()) {
            if (*it < a[u]) {
                all.erase(it);
                all.insert(a[u]);
            }
        } else all.insert(a[u]);

        return all;
    };

    multiset<int> all = dfs(dfs, 1, 0);

    for (int i = 1; i <= all.size() - 1; i++) {
        cout << -1 << " ";
    }

    ll tot = 0;
    for (int x : all) {
        tot += x;
    }

    cout << tot << " ";

    map<int, int> f;
    for (int i = 1; i <= n; i++) {
        f[a[i]]++;
    }

    for (int x : all) {
        f[x]--;
    }

    for (auto it = f.rbegin(); it != f.rend(); ++it) {
        while (it->second > 0) {
            it->second--;
            tot += it->first;
            cout << tot << " ";
        }
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