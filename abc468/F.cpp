#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

#define lc ((p) << 1    )
#define rc ((p) << 1 | 1)

const int INF = 1e9;

struct segment_tree {
    struct node {
        int l, r;
        int mx;
    };

    int n;
    vector<node> tree;

    int query(int p, int l, int r) {
        if (l <= tree[p].l && tree[p].r <= r) {
            return tree[p].mx;
        }
        int mid = (tree[p].l + tree[p].r) >> 1;

        int ans = 0;
        if (l <= mid) ans = max(ans, query(lc, l, r));
        if (r >  mid) ans = max(ans, query(rc, l, r));
        return ans;
    }

    void update(int p, int pos, int val) {
        if (tree[p].l == tree[p].r && tree[p].l == pos) {
            tree[p].mx = max(val, tree[p].mx);
            return;
        }

        int mid = (tree[p].l + tree[p].r) >> 1;
        if (pos <= mid) update(lc, pos, val);
        else            update(rc, pos, val);
        tree[p].mx = max(tree[lc].mx, tree[rc].mx);
    }

    void build(int p, int l, int r) {
        tree[p] = {l, r, 0};
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
    }

    void clear() {
        for (int i = 1; i < 4 * n; i++) {
            tree[i].mx = 0;
        }
    }

    segment_tree(int _n) : n(_n) {
        tree.resize(4 * n);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    vector<int> rem(1);
    int pmax = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > pmax) {
            pmax = a[i];
            ans++;
        } else {
            rem.push_back(a[i]);
        }
    }

    int m = rem.size() - 1;

    segment_tree st(n);
    st.build(1, 1, n);

    vector<int> dp(m + 1);
    for (int i = 1; i <= m; i++) {
        int l = 1, r = rem[i] - 1;
        if (l > r) dp[i] = 1;
        else       dp[i] = st.query(1, l, r) + 1;
        st.update(1, rem[i], dp[i]);
    }

    int mx = 0;

    for (int i = 1; i <= m; i++) {
        mx = max(mx, dp[i]);
    }

    cout << ans + mx << endl;
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