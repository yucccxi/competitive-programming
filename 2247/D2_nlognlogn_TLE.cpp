#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 0x3f3f3f3f;

#define lc ((p) << 1    )
#define rc ((p) << 1 | 1)

struct segment_tree {
    struct node {
        int l, r;
        int mn, mx;
    };

    int n;
    vector<node> tree;

    void pushup(int p) {
        tree[p].mn = min(tree[lc].mn, tree[rc].mn);
        tree[p].mx = max(tree[lc].mx, tree[rc].mx);
    }

    void update(int p, int pos, int val) {
        if (tree[p].l == tree[p].r) {
            tree[p].mn = val;
            tree[p].mx = val;
            return;
        }

        int mid = (tree[p].l + tree[p].r) >> 1;
        if (pos <= mid) update(lc, pos, val);
        else            update(rc, pos, val);
        pushup(p);
    }

    int querymn(int p, int l, int r) {
        if (l <= tree[p].l && tree[p].r <= r) {
            return tree[p].mn;
        }

        int mid = (tree[p].l + tree[p].r) >> 1;
        int ans = INF;
        if (l <= mid) ans = min(ans, querymn(lc, l, r));
        if (r >  mid) ans = min(ans, querymn(rc, l, r));
        return ans;
    }

    int querymx(int p, int l, int r) {
        if (l <= tree[p].l && tree[p].r <= r) {
            return tree[p].mx;
        }

        int mid = (tree[p].l + tree[p].r) >> 1;
        int ans = 0;
        if (l <= mid) ans = max(ans, querymx(lc, l, r));
        if (r >  mid) ans = max(ans, querymx(rc, l, r));
        return ans;
    }

    void build(int p, int l, int r, vector<int> &a) {
        tree[p] = {l, r, a[l], a[l]};
        if (l == r) return;

        int mid = (l + r) >> 1;
        build(lc, l      , mid, a);
        build(rc, mid + 1, r  , a);
        pushup(p);
    }

    segment_tree(int _n, vector<int> &a) : n(_n) {
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int lg = 32 - __builtin_clz(n);
    segment_tree st(n, a);
    vector<int> bad(lg + 1);

    auto update = [&](int l, int r, int p, int v) -> void {
        int len = 1 << p;
        int lmx = l == 0     ? 0   : st.querymx(1, l - len, l - 1);
        int cmn = st.querymn(1, l, r);
        int cmx = st.querymx(1, l, r);
        if (cmn < lmx) bad[p] += v;
    };

    for (int p = 0; p <= lg; p++) {
        int len = 1 << p;
        for (int l = 0; l < n; l += len) {
            int r = min(n - 1, l + len - 1);
            update(l, r, p, 1);
        }
    }

    for (int p = 0; p <= lg; p++) {
        if (bad[p] == 0) {
            cout << (p == 0 ? 0 : (1 << (p - 1))) << endl;
            break;
        }
    }

    while (q--) {
        int pos, v;
        cin >> pos >> v;

        for (int p = 0; p <= lg; p++) {
            int len = 1 << p;
            int l = pos / len * len;
            int r = min(n - 1, l + len - 1);
            update(l, r, p, -1);
            if (r != n - 1) {
                update(r + 1, min(n - 1, r + len), p, -1);
            }
        }

        st.update(1, pos, v);
        
        for (int p = 0; p <= lg; p++) {
            int len = 1 << p;
            int l   = pos / len * len;
            int r   = min(n - 1, l + len - 1);
            update(l, r, p, 1);
            if (r != n - 1) {
                update(r + 1, min(n - 1, r + len), p, 1);
            }
        }

        for (int p = 0; p <= lg; p++) {
            if (bad[p] == 0) {
                cout << (p == 0 ? 0 : (1 << (p - 1))) << endl;
                break;
            }
        }
    }
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