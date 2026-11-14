#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int basis[32];

bool insert(int x) {
    for (int i = 30; i >= 0; i--) {
        if (x >> i & 1) {
            if (basis[i] == 0) {
                basis[i] = x;
                return true;
            }

            x ^= basis[i];
        }
    }

    return false;
}

void solve() {
    memset(basis, 0, sizeof(basis));

    int n; cin >> n;
    int tot = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot ^= a[i];
    }

    for (int i = 1; i <= n; i++) {
        insert(a[i] & ~tot);
    }

    int xr = 0;
    for (int i = 30; i >= 0; i--) {
        xr = max(xr, xr ^ basis[i]);
    }

    cout << tot + 2 * xr << endl;
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