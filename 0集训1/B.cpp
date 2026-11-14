#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

#define MAXN 100005

struct edge {
    int p, q, weight;
    edge(int u, int v, int w) : p(u), q(v), weight(w) {}
    edge() : p(0), q(0), weight(0) {}
    int either() { return p; }
    int other(int v) { return v == p ? q : p; }
    bool operator<(const edge &other) const { return weight < other.weight; }
    bool operator>(const edge &other) const { return weight > other.weight; }
};

struct union_find {
    bool ranked;
    int components;
    vector<int> parent, sz;

    union_find(int n, bool _ranked) {
        ranked = _ranked;

        sz.resize(n + 1);
        parent.resize(n + 1);
        components = n;

        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int v) {
        while (parent[v] != v) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }

        return v;
    }

    bool unite(int v, int w) {
        int p = find(v), q = find(w);
        if (p == q) return false;

        if (ranked) {
            if (sz[q] > sz[p]) {
                swap(p, q);
            }
        }

        parent[p] = q;
        sz[q] += sz[p];

        --components;

        return true;
    }

    int count() { return components; }
};

int n, m, k;
vector<edge> G[MAXN];
vector<edge> MST;

vector<edge> edges;

bool check(int x) {
    union_find uf(n, true);
    for (edge &e : MST) {
        if (e.weight <= x) {
            uf.unite(e.p, e.q);
        }
    }

    return uf.count() > k;
}

bool ok(int x) {
    union_find uf(n, true);
    for (edge &e : MST) {
        if (e.weight <= x) {
            uf.unite(e.p, e.q);
        }
    }

    return uf.count() == k;
}

void solve() {
    cin >> n >> m >> k;

    int mx = 0;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        mx = max(mx, w);

        edge e = edge(u, v, w);
        G[u].push_back(e);
        G[v].push_back(e);

        edges.push_back(e);
    }

    sort(edges.begin(), edges.end());

    union_find uf(n, true);
    for (edge &e : edges) {
        if (uf.find(e.p) != uf.find(e.q)) {
            MST.push_back(e);
            uf.unite(e.p, e.q);
        }

        if (MST.size() == n - 1) break;
    }

    // for (edge &e : MST) {
    //     cout << e.weight << " ";
    // }
    // cout << endl;

    int l = 0, r = mx;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    if (ok(l)) {
        cout << l << endl;
    } else {
        cout << -1 << endl;
    }

    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }

    MST.clear();
    edges.clear();
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