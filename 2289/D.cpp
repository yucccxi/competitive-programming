#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct FenwickTree {
    vector<int> tree;
    int n;

    FenwickTree(int sz) {
        n = sz;
        tree.assign(n + 1, 0);
    }

    int low_bit(int x) {
        return x & (-x);
    }

    void update(int pos, int delta) {
        while (pos <= n) {
            tree[pos] += delta;
            pos += low_bit(pos);
        }
    }

    int query(int pos) {
        int sm = 0;
        while (pos > 0) {
            sm += tree[pos];
            pos -= low_bit(pos);
        }
        return sm;
    }

    int rquery(int left, int right) {
        if (left > right) return 0;
        return query(right) - query(left - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    vector<ll> discret = pref;
    sort(discret.begin() + 1, discret.end());
    discret.erase(unique(discret.begin() + 1, discret.end()), discret.end());

    if (discret[1] < 0) {
        cout << -1 << endl;
        return;
    }

    auto rk = [&](ll val) -> int {
        return lower_bound(discret.begin() + 1, discret.end(), val) - discret.begin();
    };

    // for (int i = 1; i <= n; i++) {
    //     cout << rk(pref[i]) << " ";
    // }
    // cout << endl;

    FenwickTree fw(n);

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        int j = rk(pref[i]);
        // cout << j + 1 << " " << n << " " << fw.rquery(j + 1, n) << endl;
        ans += fw.rquery(j + 1, n);
        // cout << fw.rquery(j + 1, n) << endl;
        fw.update(j, +1);
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