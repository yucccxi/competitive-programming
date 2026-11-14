#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1005;

bool s[MAXN][MAXN];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<bool> sgn(n + 1);
    vector<vector<int>> G(n + 1);

    for (int i = 1; i <= m; i++) {
        int o, p, q;
        cin >> o >> p >> q;
        s[min(p, q)][max(p, q)] = o - 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!s[i][j] && s[i][i] && s[j][j]) {
                cout << "NO" << endl;
                return;
            }

            if (s[i][j] && !s[i][i] && !s[j][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (s[i][i] == s[j][j]) {
                continue;
            }

            int p = i, q = j;
            if (s[p][p]) swap(p, q);

            if (s[min(p, q)][max(p, q)]) {
                G[q].push_back(p);
            } else {
                G[p].push_back(q);
            }
        }
    }

    vector<int> state(n + 1, 0);
    bool ok = true;

    vector<int> topo;
    auto toposort = [&](auto &&self, int u) -> void {
        if (!ok) return;

        state[u] = 1;
        
        for (int v : G[u]) {
            if (state[v] == 1) {
                ok = false;
                return;
            } else if (state[v] == 0) {
                self(self, v);
                if (!ok) return;
            }
        }

        state[u] = 2;
        topo.push_back(u);
    }; 

    for (int i = 1; i <= n; ++i) {
        if (state[i] == 0) {
            toposort(toposort, i);
        }
    }

    if (!ok) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        reverse(topo.begin(), topo.end());
    }

    vector<int> ans(n + 1);

    int cur = 1e8;
    for (int u : topo) {
        if (s[u][u]) ans[u] = -cur;
        else         ans[u] = +cur;
        cur--;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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