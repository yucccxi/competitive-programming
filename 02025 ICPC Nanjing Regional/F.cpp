#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct UnionFind {
    int n, comps;
    vector<int> parent;
    vector<int> sz;

    UnionFind(int _n) : n(_n) {
        comps = n;
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    UnionFind() {}

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] > sz[v]) swap(u, v);
        sz[v] += sz[u];
        parent[u] = v;
        --comps;
        return true;
    }

    int count() { return comps; }
};

constexpr int PW = 1 << 12;

UnionFind uf[PW];

void addEdge(int u, int v, int w) {
    if (!uf[w].merge(u, v)) return;
    for (int i = 0; i < 12; i++) {
        if (w >> i & 1)
            addEdge(u, v, w ^ (1 << i));
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < PW; i++) {
        uf[i] = UnionFind(n);
    }

    ll ans = 0;

    for (int i = 1; i <= q; i++) {
        char op; cin >> op;
        if (op == '+') {
            int u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w);
        } else if (op == '?') {
            int u, v;
            cin >> u >> v;

            if (uf[0].find(u) != uf[0].find(v)) {
                ans--;
                continue;
            }

            int cur = 0;
            for (int i = 11; i >= 0; i--) {
                int nxt = cur | (1 << i);
                if (uf[nxt].find(u) == uf[nxt].find(v)) {
                    cur = nxt;
                }
            }
            ans += cur;
        } else assert(false);
    }

    cout << ans << endl;
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