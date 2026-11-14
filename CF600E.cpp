#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e5 + 5;

int n;
int a[MAXN];
vector<int> T[MAXN];

ll ans[MAXN];

int child[MAXN], sz[MAXN];

int mxc;
ll tot_vals;
int cnt[MAXN];

void dfs0(int u, int p) {
    sz[u] = 1;

    int mx = 0;

    for (int v : T[u]) {
        if (v == p) continue;
        dfs0(v, u);
        sz[u] += sz[v];

        if (sz[v] > mx) {
            child[u] = v;
            mx = sz[v];
        }
    }
}

void calculate(int u, int p, int val, int heavy) {

    if (val == 1) {
        cnt[a[u]]++;
        if (cnt[a[u]] > mxc) {
            mxc = cnt[a[u]];
            tot_vals = a[u];
        } else if (cnt[a[u]] == mxc) {
            tot_vals += a[u];
        }
    } else cnt[a[u]]--;

    for (int v : T[u]) {
        if (v == p || v == heavy) continue;
        calculate(v, u, val, heavy);
    }
}

void dfs1(int u, int p, bool keep) {
    for (int v : T[u]) {
        if (v == p || v == child[u]) {
            continue;
        }

        dfs1(v, u, false);
    }

    if (child[u]) dfs1(child[u], u, true);
    calculate(u, p, 1, child[u]);

    ans[u] = tot_vals;

    if (!keep) {
        calculate(u, p, -1, 0);
        mxc = 0;
        tot_vals = 0;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }

    dfs0(1, 0);
    dfs1(1, 0, true);

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
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}