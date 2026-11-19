#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct Fenwick {

    int n, b;
    vector<ll> tree;

    int lowbit(int x) { return x & -x; }

    void update(int pos, ll d) {
        while (pos <= n) {
            tree[pos] += d;
            pos += lowbit(pos);
        }
    }

    ll query(int pos) {
        ll ans = 0;
        while (pos > 0) {
            ans += tree[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }

    void change(int pos, ll val) {
        ll prev = query(pos) - query(pos - 1);
        update(pos, val - prev);
    }

    ll rquery(int l, int r) {
        return query(r) - query(l - 1);
    }

    Fenwick(int _n) : n(_n) {
        b = 31 - __builtin_clz(n);
        tree.resize(n + 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> mapper(n);
    vector<int> t = a;
    for (int i = 1; i <= n - 1; i++) {
        mapper[i] = t.size();
        t.push_back(min(t[2 * i - 1], t[2 * i]));
    }

    t.push_back(0);

    Fenwick fw(n);

    for (int i = 1; i <= 2 * n; i += 2) {
        fw.update((i + 1) / 2, max(t[i], t[i + 1]));
    }

    auto update = [&](auto &&self, int pos, int val) -> void {
        int i = pos - (pos % 2 == 0);
        int j = i + 1;

        t[pos] = val;

        fw.change(j / 2, max(t[i], t[j]));

        if (j == 2 * n) return;

        int npos = mapper[j / 2];
        int nval = min(t[i], t[j]);

        self(self, npos, nval);
    };

    while (q--) {
        char c; cin >> c;
        if (c == 'A') {
            int l, r;
            cin >> l >> r;
            cout << fw.rquery(l, r) << endl;
        } else if (c == 'C') {
            int x, y;
            cin >> x >> y;

            int u = t[x], v = t[y];
            
            update(update, x, v);
            update(update, y, u);

        } else assert(false);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}