#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct persistent_segment_tree {
    struct node {
        int lc, rc;
        ll val;
    };

    int n, tot;

    vector<node> nodes;
    vector<int> heads;

    int build(int l, int r) {
        int id = nodes.size();
        nodes.push_back({0, 0, 0});

        if (l == r) { return id; }

        int mid = (l + r) >> 1;

        nodes[id].lc = build(l, mid);
        nodes[id].rc = build(mid + 1, r);

        return id;
    }

    int update0(int v, int pos, ll val, int tl, int tr) {
        int id = nodes.size();
        nodes.push_back(nodes[v]);

        if (tl == tr) {
            nodes[id].val = max(nodes[id].val, val);
            return id;
        }

        int mid = (tl + tr) >> 1;
        if (pos <= mid) {
            nodes[id].lc = update0(nodes[v].lc, pos, val, tl, mid);
            nodes[id].rc = nodes[v].rc;
        } else {
            nodes[id].rc = update0(nodes[v].rc, pos, val, mid + 1, tr);
            nodes[id].lc = nodes[v].lc;
        }

        nodes[id].val = max(nodes[nodes[id].lc].val, nodes[nodes[id].rc].val);

        return id;
    }

    void update(int v, int pos, ll val) {
        heads.push_back(update0(heads[v], pos, val, 1, n));
        tot++;
    }

    ll query0(int v, int pos, int tl, int tr) {
        if (tl == tr) return nodes[v].val;

        int mid = (tl + tr) >> 1;
        if (pos <= mid) return query0(nodes[v].lc, pos, tl     , mid);
        else            return query0(nodes[v].rc, pos, mid + 1, tr );
    }

    ll query(int v, int pos) {
        if (pos == 0) return 0;
        return query0(heads[v], pos, 1, n);
    }

    ll range_query0(int v, int l, int r, int tl, int tr) {
        if (l <= tl && tr <= r) return nodes[v].val;

        ll total = 0;

        int mid = (tl + tr) >> 1;
        if (l <= mid) total = max(total, range_query0(nodes[v].lc, l, r, tl     , mid));
        if (r >  mid) total = max(total, range_query0(nodes[v].rc, l, r, mid + 1, tr ));

        return total;
    }

    ll range_query(int v, int l, int r) {
        if (l > r) return 0;
         return range_query0(heads[v], l, r, 1, n);
    }

    // 某次需要跳过更新的时候记得复制上一个版本
    void copy() { tot++; heads.push_back(heads.back()); }

    persistent_segment_tree(int _n) : n(_n) {
        tot = 0;
        nodes.push_back({0, 0, 0});
        heads.push_back(build(1, n));
    }
};

void solve() {
    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;

    persistent_segment_tree pst(n);
    for (int i = 1; i <= n; i++) {
        ll cur = 0;
        if (i < a[i] + 1) {
            cur = a[i];
        } else {
            cur = pst.range_query(i - a[i] - 1, 1, i - 1) + a[i];
        }

        if (a[i] + i <= n) {
            pst.update(pst.tot, a[i] + i, cur);
        } else pst.copy();

        ans = max(ans, cur);
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