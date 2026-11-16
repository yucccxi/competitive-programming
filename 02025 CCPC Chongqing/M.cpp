#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN  = 2e5 + 5;
const int MAXLG = 20;

const int MAXV = 1e6 + 5;

struct Q { int val, u, v; };

int n, c;
Q all[MAXN];

vector<int> G[MAXN];

vector<int> euler(1);
int fstSeen[MAXN];

int tsp, tin[MAXN], tout[MAXN], depth[MAXN], st[MAXN << 1][MAXLG];

map<int, vector<pair<int, int>>> seen;

int spf[MAXV];

void sieve() {
    for (int i = 1; i < MAXV; i++) {
        spf[i] = i;
    }

    for (int i = 2; i < MAXV; i++) {
        if (spf[i] == i) {
            for (ll j = (ll)i * i; j < MAXV; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void dfs(int u, int p) {
    if (fstSeen[u] == 0) {
        fstSeen[u] = euler.size();
    }
    euler.push_back(u);
    
    tin[u] = ++tsp;
    depth[u] = depth[p] + 1;
    
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        euler.push_back(u);
    }

    tout[u] = tsp;
}

void initST() {
    for (int i = 1; i <= 2 * n - 1; i++) {
        st[i][0] = euler[i];
    }

    for (int j = 1; j < MAXLG; j++) {
        for (int i = 1; (i + (1 << j) - 1) <= 2 * n - 1; i++) {
            int u = st[i][j - 1];
            int v = st[i + (1 << (j - 1))][j - 1];
            if (depth[u] > depth[v]) swap(u, v);
            st[i][j] = u;
        }
    }
}

int lca(int u, int v) {
    int l = fstSeen[u], r = fstSeen[v];
    if (l > r) swap(l, r);
    int len = 31 - __builtin_clz(r - l + 1);
    int lv = st[l][len], rv = st[l - (1 << len) + 1][len];
    return depth[lv] < depth[rv] ? lv : rv;
}

pair<int, int> count(int val, int p) {
    int cnt = 0;
    while (val % p == 0) {
        val /= p;
        ++cnt;
    }
    return {cnt, val};
}

void solve() {
    cin >> n >> c;
    for (int i = 2; i <= n; i++) {
        int val, u, v;
        cin >> val >> u >> v;

        all[i] = {val, u, v};

        G[v].push_back(i);
        G[i].push_back(v);
    }

    int nc = c;
    while (nc > 1) {
        int p = spf[nc];
        auto [cnt, nval] = count(nc, p);
        nc = nval;
        seen[p].push_back({1, cnt});
    }

    dfs(1, 0);
    initST();

    for (int i = 2; i <= n; i++) {
        int val = all[i].val, u = all[i].u, v = all[i].v;
        while (val > 1) {
            int p = spf[val];
            auto [cnt, nval] = count(val, p);

            // {u, p}
            vector<pair<int, int>> &coords = seen[p];
            sort(coords.begin(), coords.end());

            vector<int> tree(coords.size() + 1);

            auto rk = [&]()

            val = nval;
        }

        while (val > 1) {
            int p = spf[val];
            auto [cnt, nval] = count(val, p);
            val = nval;
            seen[p].push_back({i, cnt});
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}