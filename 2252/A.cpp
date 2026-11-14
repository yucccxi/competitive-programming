#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    map<int, int> f;
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        f[x]++;
        tot += x;
    }

    ll mxf = 0, mxval = 0;
    for (auto &[k, v] : f) {
        if (v > mxf) {
            mxf = v;
            mxval = k;
        }
    }

    if (mxf <= n - mxf + 1) {
        cout << tot << endl;
    } else {
        cout << tot - mxf * mxval + (n - mxf + 2) * mxval << endl;
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