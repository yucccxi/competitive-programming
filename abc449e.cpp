#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct V {
    int v, f;
    bool operator<(const V &o) const {
        return f < o.f;
    }
};

struct fenwick {

    int n, maxbit;
    vector<int> tree;

    int lowbit(int x) { return x & -x; }

    void inc(int v) {
        while (v <= n) {
            tree[v]++;
            v += lowbit(v);
        }
    }

    int kth(int k) {
        int idx = 0;
        int tot = 0;
        for (int i = maxbit; i > 0; i >>= 1) {
            int nidx = idx + i;
            if (nidx <= n && tot + tree[nidx] < k) {
                idx = nidx;
                tot += tree[nidx];
            }
        }

        return idx + 1;
    }

    fenwick(int _n) : n(_n) {
        tree.resize(n + 1);
        maxbit = (1 << (31 - __builtin_clz(n)));
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<V> freq(m + 1);
    for (int i = 1; i <= m; i++) {
        freq[i].v = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        freq[a[i]].f++;
    }

    freq[0].f = 0;

    sort(freq.begin() + 1, freq.end());

    int q; cin >> q;
    vector<pair<ll, int>> queries(q + 1);
    vector<int> ans(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(queries.begin() + 1, queries.end());

    fenwick fw(m);

    int l = 0;
    ll tot = 0;
    for (int i = 1; i <= q; i++) {
        auto [u, v] = queries[i];
        if (u <= n) {
            ans[v] = a[u];
            continue;
        }

        u -= n;

        while (l < m && u > (tot + (ll)l * (freq[l + 1].f - freq[l].f))) {
            tot += l * (freq[l + 1].f - freq[l].f);
            ++l;
            while (l < m && freq[l].f == freq[l + 1].f) {
                fw.inc(freq[l++].v);
            }
            fw.inc(freq[l].v);
        }

        int k  = (u - tot - 1) % l + 1;
        ans[v] = fw.kth(k);
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
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