#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

#define lc ((p) << 1    )
#define rc ((p) << 1 | 1)

const int MOD = 998244353;

struct segment_tree {

    struct node {
        int l, r;
        ll sm, multag;
    };

    int n;
    vector<node> tree;

    void build(int p, int l, int r) {
        tree[p] = {l, r, 0, 1};
        if (l == r) return;

        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
    }

    void pushup(int p) {
        tree[p].sm = (tree[lc].sm + tree[rc].sm) % MOD;
    }

    void pushdown(int p) {
        ll multag = tree[p].multag;
        if (multag > 1) {
            tree[lc].multag = (tree[lc].multag * multag) % MOD;
            tree[lc].sm = (tree[lc].sm * multag) % MOD;
            tree[rc].multag = (tree[rc].multag * multag) % MOD;
            tree[rc].sm = (tree[rc].sm * multag) % MOD;
            tree[p].multag = 1;
        }
    }

    void mul(int p, int l, int r, ll v) {
        if (l <= tree[p].l && tree[p].r <= r) {
            tree[p].multag = (tree[p].multag * v) % MOD;
            tree[p].sm = (tree[p].sm * v) % MOD;
            return;
        }

        int mid = (tree[p].l + tree[p].r) >> 1;

        pushdown(p);
        if (l <= mid) mul(lc, l, r, v);
        if (r >  mid) mul(rc, l, r, v);
        pushup(p);
    }

    void increase(int p, int i, ll v) {
        if (tree[p].l == i && tree[p].r == i) {
            tree[p].sm = (tree[p].sm + v) % MOD;
            return;
        }

        int mid = (tree[p].l + tree[p].r) >> 1;

        pushdown(p);
        if (i <= mid) increase(lc, i, v);
        if (i >  mid) increase(rc, i, v);
        pushup(p);
    }

    ll query(int p, int i) {
        if (i <= 0 || i > n) { return 1; }

        if (tree[p].l == i && tree[p].r == i) {
            return tree[p].sm;
        }

        int mid = (tree[p].l + tree[p].r) >> 1;

        pushdown(p);
        if (i <= mid) return query(lc, i);
        if (i >  mid) return query(rc, i);
        
        return 0;
    }

    segment_tree(int _n) : n(_n) {
        tree.resize(4 * n);
        build(1, 1, n);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> pref(1), suff(1);
    int p = 0, q = 0, mx;

    mx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > mx) {
            mx = a[i];
            pref.push_back(mx);
            p++;
        }
    }

    mx = 0; 
    for (int i = n; i >= 1; i--) {
        if (a[i] > mx) {
            mx = a[i];
            suff.push_back(mx);
            q++;
        }
    }
    reverse(suff.begin() + 1, suff.end());

    int tot_mx = pref.back();

    vector<int> dpl(n + 1), dpr(n + 1);

    segment_tree cl(p);
    for (int i = 1; i <= n; i++) {
        int l = 1, r = p;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pref[mid] >= a[i]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        // l
        cl.mul(1, l, p, 2);
        if (pref[l] == a[i]) {
            cl.increase(1, l, cl.query(1, l - 1));
        }

        // 一些细节要注意...
        if (a[i] == tot_mx) {
            dpl[i] = cl.query(1, p - 1);
        }
    }

    segment_tree cr(q);
    for (int i = n; i >= 1; i--) {
        int l = 1, r = q;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (suff[mid] >= a[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // r
        cr.mul(1, 1, r, 2);

        if (suff[r] == a[i]) {
            cr.increase(1, r, cr.query(1, r + 1));
        }

        if (a[i] == tot_mx) {
            dpr[i] = cr.query(1, 2);
        }
    }

    ll ans = 0;
    ll contr = 0;
    for (int r = 1; r <= n; r++) {
        ans = (ans + contr * dpr[r]) % MOD;
        ans = (ans + (ll)dpl[r] * dpr[r]) % MOD;
        contr = (contr * 2 + dpl[r]) % MOD;
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