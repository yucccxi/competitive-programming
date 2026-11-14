#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int MAXN = 5e5 + 5;

int n, q;
int idx[MAXN];
set<int> ancestors[MAXN];
vector<int> T[MAXN];

ll ans;

void dfs(int u, ll d) {
    ans += d;
    for (int v : T[u]) {
        dfs(v, d + 1);
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        // ancestors[i].insert(x);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        ancestors[u].insert(v);
    }

    for (int i = 1; i <= n; i++) {
        idx[i] = i;
    }

    for (int u = n; u >= 2; u--) {
        if (ancestors[idx[u]].size() == 0) {
            T[1].push_back(u);
            continue;
        }

        int v = *ancestors[idx[u]].rbegin();
        T[v].push_back(u);

        if (ancestors[idx[v]].size() < ancestors[idx[u]].size()) {
            swap(idx[u], idx[v]);
        }

        for (int x : ancestors[idx[u]]) {
            ancestors[idx[v]].insert(x);
        }

        ancestors[idx[v]].erase(v);
        ancestors[idx[u]].clear();
    }

    for (int i = 1; i <= n; i++) {
        for (int x : T[i]) {
            cout << i << " -> " << x << endl;
        }
    }

    dfs(1, 0);

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}