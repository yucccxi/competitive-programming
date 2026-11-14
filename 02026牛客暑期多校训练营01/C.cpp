#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct weighted_union_find {
    int n, m;
    vector<int> weight;
    vector<int> parent;
    vector<int> val;
    vector<int> sz;

    int getid(int x, int y) {
        return (x - 1) * m + y;
    }

    void setval(int u, int value) { val[u] = value;            }
    int  getval(int u)            { return val[u];             }
    int  size(int u)              { return sz[u];              }
    int  getweight(int u)         { find(u); return weight[u]; }

    bool unite(int u, int v) {
        int p = find(u), q = find(v);
        if (p == q) return false;
        parent[p] = q;
        sz[q] += sz[p];
        weight[p] = val[v] - sz[p] + 1;
        return true;
    }

    int find(int u) {
        if (u == parent[u]) return u;
        int orgi = parent[u];
        parent[u] = find(parent[u]);
        weight[u] = max(weight[u], weight[orgi]);
        return parent[u];
    }

    weighted_union_find(int _n, int _m) : n(_n), m(_m) {
        weight.resize(n * m + 1);
        parent.resize(n * m + 1);
        val.resize(n * m + 1);
        sz.resize(n * m + 1);
        for (int i = 1; i <= n * m; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
};

int n, m, q;
int l = 0;

vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void solve() {
    cin >> n >> m >> q;
    weighted_union_find uf(n, m);

    while (q--) {
        int op; cin >> op;

        if (op == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            x ^= l, y ^= l;

            int id = uf.getid(x, y);
            uf.setval(id, v);

            for (auto &[dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
                int nid = uf.getid(nx, ny);
                if (uf.getval(nid) == 0) continue;
                uf.unite(nid, id);
            }

            l = uf.size(id) - 1;
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            x ^= l, y ^= l;
            int id = uf.getid(x, y);

            l = max(0, uf.getweight(id) - uf.getval(id));
        } else assert(false);

        cout << l << endl;
    }
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