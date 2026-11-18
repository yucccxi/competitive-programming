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

    void kth(int k) {
        int pw = (1 << b);
        int pos = 0, cnt = 0;
        while (pw > 0) {
            int npos = pos + pw, ncnt = cnt + tree[pw];
            if (npos <= n && ncnt < k) {
                pos = npos, cnt = ncnt;
            }
        }

        return pos < n ? n + 1 : -1;
    }

    Fenwick(int _n) : n(_n) {
        tree.resize(n + 1);
        b = 31 - __builtin_clz(n);
    }
};

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}