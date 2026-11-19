#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct Fenwick {
    
    int n, b;
    vector<int> tree;

    int lowbit(int x) { return x & -x; }

    void update(int pos, int delta) {
        while (pos <= n) {
            tree[pos] += delta;
            pos += lowbit(pos);
        }
    }

    int kth(int k) {
        int pw = (1 << b);
        int pos = 0, cnt = 0;
        while (pw > 0) {
            int npos = pos + pw;
            if (npos <= n && cnt + tree[npos] < k) {
                pos = npos, cnt += tree[npos];
            }
            pw >>= 1;
        }

        return pos < n ? pos + 1 : -1;
    }

    Fenwick(int _n) : n(_n) {
        tree.resize(n + 1);
        b = 31 - __builtin_clz(n);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    Fenwick fw(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        fw.update(x, 1);
    }

    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        if (x > 0) {
            fw.update(x, 1);
        } else {
            int val = fw.kth(-x);
            fw.update(val, -1);
        }
    }

    int ans = fw.kth(1);
    cout << (ans == -1 ? 0 : ans) << endl;
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