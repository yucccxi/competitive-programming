#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct fenwick {

    int n;
    vector<int> tree;

    int lowbit(int x) {
        return x & -x;
    }

    void update(int pos, int v) {
        while (pos <= n) {
            tree[pos] += v;
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

    ll query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }

    void clear() {
        fill(tree.begin(), tree.end(), 0);
    }

    fenwick(int _n) : n(_n) {
        tree.resize(n + 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    int orgq = q;

    vector<int> cnt(n + 1);
    fenwick fw(q);
    int inc = 0, tot = 0;
    
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos; cin >> pos;
            if (cnt[pos] > 0) fw.update(cnt[pos], -1);
            
            cnt[pos]++;
            if (cnt[pos] == 1) {
                tot++;
            }

            fw.update(cnt[pos], +1);
        } else if (op == 2) {
            int x; cin >> x;
            cout << fw.query_range(x + inc, orgq) << endl;
        } else assert(false);

        if (fw.query_range(inc + 1, orgq) == n) {
            ++inc;
        }
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