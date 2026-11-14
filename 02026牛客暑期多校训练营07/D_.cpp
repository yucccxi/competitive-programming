#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

#define lc ((p) << 1    )
#define rc ((p) << 1 | 1)

struct segment_tree {
    struct node {
        int l, r;
        int mx;
    };

    int n;
    vector<node> tree;

    void build(int p, int l, int r) {
        tree[p] = {l, r, 0};
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
    }

    int query_max() {
        return tree[1].mx;
    }

    void update(int p, int pos, int value) {
        if (tree[p].l == tree[p].r) {
            assert(tree[p].l == pos);
            tree[p].mx = value;
            return;
        }

        int mid = (tree[p].l + tree[p].r) >> 1;
        if (pos <= mid) update(lc, pos, value);
        if (pos >  mid) update(rc, pos, value);
        tree[p].mx = max(tree[lc].mx, tree[rc].mx);
    }

    segment_tree(int _n) : n(_n) {
        tree.resize(n << 2);
        build(1, 1, n);
    }
};

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }

    vector<int> posp(n + 1), posq(n + 1);
    for (int i = 1; i <= n; i++) {
        posp[p[i]] = i;
        posq[q[i]] = i;
    }

    int u = posp[x], v = posq[x];

    segment_tree st1(n), st2(n);
    for (int i = n; i > u; i--) {
        st1.update(1, p[i], posq[p[i]]);
    }
    for (int i = n; i > v; i--) {
        st2.update(1, q[i], posp[q[i]]);
    }

    vector<int> ans;

    for (int i = 1; i <= n - 1; i++) {
        {
            int mx = st1.query_max();
            if (mx != 0 && mx < v) {
                for (int j = v - 1; j > mx; j--) {
                    st2.update(1, q[j], posp[q[j]]);
                }
                v = mx;
                st1.update(1, q[mx], 0);
                ans.push_back(q[mx]);
                continue;
            }
        }

        {
            int mx = st2.query_max();
            if (mx > 0 && mx < u) {
                for (int j = u - 1; j > mx; j--) {
                    st1.update(1, p[j], posq[p[j]]);
                }
                u = mx;
                st2.update(1, p[mx], 0);
                ans.push_back(p[mx]);
                continue;
            }
        }

        cout << "NO" << endl;
        return;
    }

    reverse(ans.begin(), ans.end());

    cout << "YES" << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
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