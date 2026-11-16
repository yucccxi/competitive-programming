#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

ll pw2[MAXN];

struct Meta { int u, lvl, carry; };

void solve() {
    int n; cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= n - 1; i++) {
    	int u, v;
    	cin >> u >> v;
    	G[u].push_back(v);
        G[v].push_back(u);
    }

    string s, t;
    cin >> s >> t;
    s = '.' + s, t = '.' + t;

    vector<bool> visited(n + 1);
    vector<bool> marked(n + 1);
    vector<bool> force(n + 1);

   	queue<Meta> q;
   	q.push({1, 0, 0});

   	while (q.size() > 0) {
   		Meta &meta = q.front();
   		q.pop();

        marked[meta.u] = true;

        int ncarry;

   		if (!visited[meta.lvl]) {
   			int val = s[meta.u] - '0' + meta.carry;
            if ((val & 1) != t[meta.u] - '0') {
                force[meta.lvl] = true;
                ++val;
            }

            ncarry = val / 2;
            visited[meta.lvl] = true;
   		} else {
            int val = s[meta.u] - '0' + meta.carry;
            if (
                force[meta.lvl] && (val & 1) == t[meta.u] - '0' ||
                !force[meta.lvl] && (val & 1) != t[meta.u] - '0'
            ) {
                cout << -1 << endl;
                return;
            }

            val += force[meta.lvl];

            ncarry = val / 2;
            visited[meta.lvl] = true;
        }

        for (int v : G[meta.u]) {
            if (marked[v]) continue;
            q.push({v, meta.lvl + 1, ncarry});
        }
   	}

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (force[i]) {
            ans += pw2[i];
        }
    }

    ans %= MOD;

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pw2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pw2[i] = pw2[i - 1] * 2;
        pw2[i] %= MOD;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}