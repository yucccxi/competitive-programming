#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if (n % 2 == 0) {
        cout << n + 1 << endl;
        return;
    }

    auto check = [&](int k, int vert) {
        vector<int> comp(n + 1, -1);
        int cid = 0;

        for (int s = 1; s <= n; s++) {
            if (s == vert || comp[s] != -1) continue;

            queue<int> q;
            q.push(s);
            comp[s] = cid;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : G[u]) {
                    if (v == vert || comp[v] != -1) continue;
                    comp[v] = cid;
                    q.push(v);
                }
            }

            cid++;
        }

        for (int a = 1; a <= n; a++) {
            if (a == vert) continue;

            int b = k - a;
            if (b < 1 || b > n || b == a) continue;

            if (comp[a] != comp[b]) return true;
        }

        return false;
    };

    int ks[3] = {n, n + 1, n + 2};
    int qs[3] = {n, (n + 1) / 2, 1};

    for (int i = 0; i < 3; i++) {
        if (check(ks[i], qs[i])) {
            cout << ks[i] << endl;
            return;
        }
    }

    cout << n << endl;
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