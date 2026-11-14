#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using int128 = __int128_t;

#define endl '\n'

pair<int128, int> basis[128];

bool insert(int128 mask, int v) {
    for (int i = 105; i >= 0; i--) {
        if (mask >> i & 1) {
            if (basis[i].first == 0) {
                basis[i] = {mask, v};
                return true;
            }
            mask ^= basis[i].first ;
            v    ^= basis[i].second;
        }
    }

    return false;
}

int query(int128 mask) {
    int ans = 0;
    for (int i = 105; i >= 0; i--) {
        if (mask >> i & 1) {
            if (basis[i].first == 0) {
                return -1;
            }

            mask ^= basis[i].first ;
            ans  ^= basis[i].second;
        }
    }

    return ans;
}

void solve() {

    for (int i = 0; i < 128; i++) {
        basis[i] = {};
    }

    int k; cin >> k;

    for (int i = 1; i <= k; i++) {
        int c, s;
        cin >> c >> s;

        int128 mask = 0;
        for (int j = 1; j <= c; j++) {
            int l; cin >> l;
            mask ^= (int128)1 << l;
        }

        insert(mask, s);
    }

    int q; cin >> q;
    while (q--) {
        int d; cin >> d;
        int128 mask = 0;
        for (int i = 1; i <= d; i++) {
            int l; cin >> l;
            mask ^= (int128)1 << l;
        }

        cout << query(mask) << endl;
    }
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