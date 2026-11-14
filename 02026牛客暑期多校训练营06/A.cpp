#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int MOD = 998244353;

struct union_find {

    int n;
    vector<int> parent;
    vector<int> sz;
    vector<int> solts;

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v) {
        int p = find(u), q = find(v);
        if (p == q) return false;
        if (sz[p] > sz[q]) swap(p, q);
        solts[q] += solts[p];
        sz[q] += sz[p];
        parent[p] = q;
        return true;
    }

    void emplace(int u) {
        int p = find(u);
        --solts[p];
    }

    int soltcnt(int u) {
        int p = find(u);
        return solts[p];
    }

    union_find(int _n) : n(_n) {
        parent.resize(n + 1);
        sz.resize(n + 1);
        solts.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
            solts[i] = 1;
        }
    };
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    ll ans = 1;

    union_find uf(n);
    for (int i = n; i >= 1; i--) {
        int j = pos[i];

        int cnt = uf.soltcnt(j);
        ans *= cnt;
        ans %= MOD;

        uf.emplace(j);
        if (j > 1 && j < n && uf.soltcnt(j - 1) > 0 && uf.soltcnt(j + 1) > 0) {
            uf.merge(j - 1, j + 1);
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