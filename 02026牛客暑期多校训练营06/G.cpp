#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    queue<int> q;
    vector<bool> st(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= k; i++) {
        int u; cin >> u;
        st[u] = true;
        cnt[u] = 2;
        q.push(u);
    }

    vector<int> ans;
    vector<bool> marked(n + 1);
    while (q.size() > 0) {
        int u = q.front();
        q.pop();

        if (marked[u]) continue;

        marked[u] = true;

        for (int v : G[u]) {
            if (!marked[v] && cnt[u] >= 2) {
                cnt[v]++;
                if (cnt[v] >= 2) {
                    q.push(v);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i] && cnt[i] >= 1) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
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