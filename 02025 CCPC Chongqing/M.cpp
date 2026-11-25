#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN  = 2e5 + 5;
const int MAXLG = 20;
const int MAXV  = 1e6 + 5;
const int MAXP  = 1e5 + 5;

struct Q { int val, u, v; };

int n;
int a[MAXN];

Q all[MAXN];

vector<int> G[MAXN];

vector<int> euler(1);
int fstSeen[MAXN];

int tsp, parent[MAXN], tin[MAXN], tout[MAXN], depth[MAXN], st[MAXN << 1][MAXLG];

vector<int> primes(1);
int spf[MAXV], pid[MAXV];

vector<pair<int, int>> fac[MAXV];

vector<int> fenwick[MAXP];
vector<int> coords[MAXP];

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

    for (int i = 2; i < MAXV; i++) {
        if (spf[i] == i) {
            pid[i] = primes.size();
            primes.push_back(i);
        }
    }

    for (int i = 2; i < MAXV; i++) {
        int val = i;
        while (val > 1) {
            int p = spf[val];
            int cnt = 0;
            while (val % p == 0) {
                val /= p;
                ++cnt;
            }
            fac[i].push_back({p, cnt});
        }
    }
}

void dfs(int u, int p) {
    parent[u] = p;

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
    int lv = st[l][len], rv = st[r - (1 << len) + 1][len];
    return depth[lv] < depth[rv] ? lv : rv;
}

int lowbit(int x) { return x & -x; }

// tsp
int fwQuery(int p, int t) {
    int pos = upper_bound(coords[p].begin(), coords[p].end(), t) - coords[p].begin();
    int ans = 0;
    for (; pos > 0; pos -= lowbit(pos)) {
        ans += fenwick[p][pos];
    }
    return ans;
}

void fwUpdate(int p, int t, int delta) {
    int pos = upper_bound(coords[p].begin(), coords[p].end(), t) - coords[p].begin();
    int m = fenwick[p].size();

    if (pos == 0) return;

    for (; pos < m; pos += lowbit(pos)) {
        fenwick[p][pos] += delta;
    }
}

void solve() {
    cin >> n >> a[1];

    all[1].val = a[1];
    all[1].u = 1;
    all[1].v = 1;
    for (int i = 2; i <= n; i++) {
        int val, u, v;
        cin >> val >> u >> v;

        all[i] = {val, u, v};

        G[v].push_back(i);
        G[i].push_back(v);

        a[i] = val;
    }

    dfs(1, 0);
    initST();

    for (int i = 1; i <= n; i++) {
        int val = all[i].val, u = all[i].u, v = all[i].v;

        for (auto &[p, c] : fac[val]) {
            coords[pid[p]].push_back(tin[i]);
            coords[pid[p]].push_back(tout[i] + 1);
        }
    }

    for (int i = 1; i < MAXP; i++) {
        sort(coords[i].begin(), coords[i].end());
        coords[i].erase(unique(coords[i].begin(), coords[i].end()), coords[i].end());
        fenwick[i].resize(coords[i].size() + 1);
    }

    for (auto &[p, c] : fac[a[1]]) {
        fwUpdate(pid[p], tin[1], c);
        fwUpdate(pid[p], tout[1] + 1, -c);
    }

    for (int i = 2; i <= n; i++) {
        int val = all[i].val, u = all[i].u, v = all[i].v;
        int L = lca(u, v);
        int nval = 1;
        for (auto &[p, c] : fac[val]) {
            int S = fwQuery(pid[p], tin[u]) + fwQuery(pid[p], tin[v]) - fwQuery(pid[p], tin[L]) - fwQuery(pid[p], tin[parent[L]]);
            int D = max(0, c - S);
            for (int j = 0; j < D; j++) nval *= p;
            fwUpdate(pid[p], tin[i], D);
            fwUpdate(pid[p], tout[i] + 1, -D);
        }
        a[i] = nval;
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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