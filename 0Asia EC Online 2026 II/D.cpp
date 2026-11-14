#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;
const int MAXN = 3e5;

#define lc (p << 1    )
#define rc (p << 1 | 1)

struct segment_tree {
    struct node {
        int l, r;
        int sm, tag;
    };

    int n;
    vector<node> tree;

    void pushup(int p) {
        tree[p].sm = tree[lc].sm + tree[rc].sm;
    }

    void pushdown(int p) {
        int tag = tree[p].tag;
        if (tag != -1) {
            tree[lc].sm = tag * (tree[lc].r - tree[lc].l + 1);
            tree[rc].sm = tag * (tree[rc].r - tree[rc].l + 1);
            tree[lc].tag = tag;
            tree[rc].tag = tag;
            tree[p ].tag = -1;
        }
    }

    void build(int p, int l, int r) {
        tree[p] = {l, r, 1, -1};
        if (l == r) return;

        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(p);
    }

    int query(int p, int l, int r) {
        if (l <= tree[p].l && tree[p].r <= r) {
            return tree[p].sm;
        }

        pushdown(p);
        int ans = 0;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if (l <= mid) ans += query(lc, l, r);
        if (r >  mid) ans += query(rc, l, r);
        return ans;
    }

    void update(int p, int l, int r, int v) {
        if (l <= tree[p].l && tree[p].r <= r) {
            tree[p].tag = v;
            tree[p].sm  = (tree[p].r - tree[p].l + 1) * v;
            return;
        }

        pushdown(p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if (l <= mid) update(lc, l, r, v);
        if (r >  mid) update(rc, l, r, v);
        pushup(p);
    }

    segment_tree(int _n) : n(_n) {
        tree.resize(4 * n + 4);
        build(1, 1, n);
    }
};

ll fac[MAXN], invfac[MAXN];

ll modpow(ll a, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    invfac[MAXN - 1] = modpow(fac[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

ll comb(ll n, ll k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> all(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> all[i].first >> all[i].second;
    }

    sort(all.begin() + 1, all.end(), [&](const auto &p1, const auto &p2) -> bool {
        if (p1.second != p2.second) {
            return p1.second < p2.second;
        }
        return __builtin_clz(p1.first) < __builtin_clz(p2.first);
    });

    // 判断一下相同的 x 不在一条链上的情况

    int l = 1;
    while (l <= q) {
        int r = l;
        while (r <= q && all[r].second == all[l].second) {
            ++r;
        }

        int prev = all[l].first;
        for (int i = l + 1; i < r; i++) {
            int cur = all[i].first;
            while (prev > cur) {
                prev >>= 1;
            }

            if (prev < cur) {
                cout << 0 << endl;
                return;
            }
        }

        l = r;
    }

    int N = (1 << (n + 1)) - 1;
    int leaves = 1 << n;

    int last = (1 << n) - 1;

    vector<bool> used(leaves + 1);

    ll ans = 1;
    int tot_used = 0;

    segment_tree st(leaves + 1);

    for (int i = 1; i <= q; i++) {
        auto &[u, x] = all[i];
        int L = u, R = u;
        while (L <= last) {
            L <<= 1;
        }

        while (R <= last) {
            R = R << 1 | 1;
        }

        L -= last, R -= last;

        int rem   = x - tot_used;
        int solts = st.query(1, L, R);

        if (!used[x]) {
            ans = ans * comb(rem - 1, solts - 1) % MOD * fac[solts] % MOD;
            used[x] = true;
        } else {
            ans = ans * comb(rem, solts) % MOD * fac[solts] % MOD;
        }

        st.update(1, L, R, 0);
        tot_used += solts;
    }

    ans = (ans * fac[leaves - tot_used] % MOD);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}