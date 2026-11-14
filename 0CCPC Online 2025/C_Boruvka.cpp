#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

struct meta {
    int u, v, w;
    meta(int _u = 0, int _v = 0, int _w = INF) : u(_u), v(_v), w(_w) {}
    bool operator<(const meta &o) const {
        return w > o.w;
    }
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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= k;
    }

    sort(a.begin() + 1, a.end());

    union_find uf(n, true);
    vector<int> nxt(n + 1);
    vector<meta> best(n + 1);

    ll ans = 0;

    while (uf.count() > 1) {
        nxt[n] = n + 1;
        for (int i = n - 1; i >= 1; i--) {
            nxt[i] = ((uf.find(i) != uf.find(i + 1)) ? (i + 1) : nxt[i + 1]);
        }

        for (int i = 1; i <= n; i++) {
            int cid = uf.find(i);
            int pos = lower_bound(a.begin() + 1, a.end(), k - a[i]) - a.begin();
            if (pos <= n) {
                int npos = (cid == uf.find(pos)) ? nxt[pos] : pos;
                if (npos <= n) {
                    int nw = a[npos] + a[i];
                    if (nw >= k) nw -= k;

                    if (nw < best[cid].w) {
                        best[cid].w = nw;
                        best[cid].u = i;
                        best[cid].v = npos;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            int cid = uf.find(i);
            int pos = (cid == uf.find(1)) ? nxt[1] : 1;
            if (pos <= n) {
                int nw = a[pos] + a[i];
                if (nw >= k) nw -= k;

                if (nw < best[cid].w) {
                    best[cid].w = nw;
                    best[cid].u = i;
                    best[cid].v = pos;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (best[i].w != INF) {
                if (uf.find(best[i].u) != uf.find(best[i].v)) {
                    uf.unite(best[i].u, best[i].v);
                    ans += best[i].w;
                    // cout << best[i].u << " " << best[i].v << endl;
                }
                best[i] = meta();
            }
        }
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