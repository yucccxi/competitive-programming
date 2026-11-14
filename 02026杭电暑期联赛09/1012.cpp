#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct fenwick {
    int n;
    vector<ll> tree;

    fenwick(int _n) : n(_n) {
        tree.resize(n + 1);
    }

    int lowbit(int x) {
        return x & -x;
    }

    void update(int i, int x) {
        while (i <= n) {
            tree[i] += x;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i -= lowbit(i);
        }
        return ret;
    }

    int query_range(int l, int r) {
        assert(l >= 1);
        return query(r) - query(l - 1);
    }

    void clear() {
        tree.clear();
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int> b(n + 1);
    for (int i = 2; i <= n - 1; i++) {
        b[i] = a[i + 1] + a[i - 1];
    }

    vector<int> idx;
    for (int i = 2; i <= n - 1; i++) {
        idx.push_back(i);
    }

    sort(idx.begin(), idx.end(), [&](const int i, const int j) -> bool {
        return a[i] < a[j];
    });

    ll cnt = 0;

    fenwick fw(2 * mx);

    int l = 0;
    while (l < idx.size()) {
        int r = l;
        while (r < idx.size() && a[idx[l]] == a[idx[r]]) {
            r++;
        }

        for (int i = l; i < r; i++) {
            int j = idx[i];
            int val = b[j];
            cnt += fw.query(val - 1);
        }

        for (int i = l; i < r; i++) {
            int j = idx[i];
            int val = b[j];
            fw.update(b[j], 1);
        }

        l = r;
    }

    for (int i = 2; i <= n - 2; i++) {
        if ((ll)(a[i] - a[i + 1]) * (b[i] - b[i + 1]) > 0) {
            --cnt;
        }
    }

    auto calc = [&](int i) -> ll {
        return (ll)(a[i] - a[i + 1]) * (a[i] - a[i + 1]);
    };

    auto check = [&](int i, int j) -> bool {
        ll delta = 0;
        if (j == i + 1) {
            swap(a[i], a[j]);
            if (i > 1) delta += calc(i - 1);
            delta += calc(i);
            if (j < n) delta += calc(j);
            swap(a[i], a[j]);
            if (i > 1) delta -= calc(i - 1);
            delta -= calc(i);
            if (j < n) delta -= calc(j);
        } else {
            swap(a[i], a[j]);
            if (i > 1) delta += calc(i - 1);
            delta += calc(i);
            delta += calc(j - 1);
            if (j < n) delta += calc(j);
            swap(a[i], a[j]);
            if (i > 1) delta -= calc(i - 1);
            delta -= calc(i);
            delta -= calc(j - 1);
            if (j < n) delta -= calc(j);
        }

        return delta > 0;
    };

    for (int i = 2; i <= n - 1; i++) {
        cnt += check(1, i);
        cnt += check(i, n);
        if (i < n - 1) cnt += check(i, i + 1);
    }

    cnt += check(1, n);

    cout << cnt << endl;
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