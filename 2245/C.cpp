#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        if (k == 1) {
            cout << "YES" << endl;
            cout << 0 << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }

    k ^= n;

    int msb = 32 - __builtin_clz(n - 1);

    // cout << ( 1 << msb ) << endl;

    if (k >= (1 << msb)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<int> skip;

    for (int i = 0; i < 30; i++) {
        if (k >> i & 1) {
            skip.push_back(1 << i);
        }
    }

    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (pos < skip.size() && i == skip[pos]) {
            pos++;
            continue;
        }

        cout << i << " ";
    }

    cout << 0 << " ";

    for (int x : skip) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        // cout << "--- " << endl;
        solve();
    }

    return 0;
}