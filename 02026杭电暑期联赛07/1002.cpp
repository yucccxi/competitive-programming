#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

ll cheight(int n, vector<vector<int>> T) {
    auto dfs = [&](auto &&self, int u, int p) -> ll {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int v : T[u]) {
            if (v == p) continue;
            ll child = self(self, v, u);
            pq.push(child);
        }

        while (pq.size() >= 3) {
            ll p = pq.top(); pq.pop();
            ll q = pq.top(); pq.pop();
            ll w = max(p, q) + 1;
            pq.push(w);
        }

        ll ans = -1;
        if (pq.size() > 0) {
            ll p = pq.top(); pq.pop();
            ans = max(ans, p);
        }

        if (pq.size() > 0) {
            ll p = pq.top(); pq.pop();
            ans = max(ans, p);
        }

        ++ans;

        return ans;
    };

    ll ans = dfs(dfs, 1, 0);

    return ans;
}

ll ctotheight(int n, vector<vector<int>> T) {

    ll ans = 0;

    auto dfs = [&](auto &&self, int u, int p) -> ll {
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        ll sz = 0;

        for (int v : T[u]) {
            if (v == p) continue;
            ll child = self(self, v, u);
            pq.push(child);
            sz += child;
        }

        while (pq.size() >= 3) {
            ll p = pq.top(); pq.pop();
            ll q = pq.top(); pq.pop();
            ans += p + q;
            pq.push(p + q);
        }

        ans += sz;

        return sz + 1;
    };

    dfs(dfs, 1, 0);

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> T(n + 1);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        T[i].push_back(p);
        T[p].push_back(i);
    }

    cout << cheight(n, T) << " " << ctotheight(n, T) << endl;
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