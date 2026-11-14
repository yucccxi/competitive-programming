#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

#define lc ((p) << 1    )
#define rc ((p) << 1 | 1)

const int MAXN = 2e5 + 5;

int n, q;
ll a[MAXN];
int dp[61][MAXN], pref[61][MAXN];

vector<ll> discret;
unordered_map<ll, int> cached_discret_value;

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

int discret_value(ll raw) {
    return lower_bound(discret.begin(), discret.end(), raw) - discret.begin() + 1;
}

void precompute() {
    for (int i = 1; i <= n; i++) {
        discret.push_back(a[i]);
    }
    sort(discret.begin(), discret.end());
    discret.erase(unique(discret.begin(), discret.end()), discret.end());

    for (int i = 1; i <= n; i++) {
        dp[1][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        ll raw = a[i];
        cached_discret_value[(raw + 2) / 3] = discret_value((raw + 2) / 3);
        cached_discret_value[raw / 2 + 1] = discret_value(raw / 2 + 1);
        cached_discret_value[raw] = discret_value(raw);
    }
}


void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    precompute();

    segment_tree st(discret.size());
    st.build(1, 1, discret.size());

    for (int j = 2; j <= 60; j++) {
        for (int i = 1; i <= n; i++) {
            ll raw = a[i];

            int lo = cached_discret_value[(raw + 2) / 3];
            int hi = cached_discret_value[raw / 2 + 1] - 1;

            if (lo <= hi) dp[j][i] = st.query(1, lo, hi);
            st.update(1, cached_discret_value[a[i]], dp[j - 1][i]);
        }

        st.clear();
    }

    for (int j = 1; j <= 60; j++) {
        for (int i = 1; i <= n; i++) {
            pref[j][i] = dp[j][i];
            pref[j][i] = max(pref[j][i], pref[j][i - 1]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = 1;
        for (int j = 60; j >= 1; j--) {
            if (pref[j][r] >= l) {
                ans = j;
                break;
            }
        }

        cout << ans << endl;
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