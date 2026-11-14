#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int dp0 = 1, dp1 = 1;
    for (int i = 2; i <= n; i++) {
        int ndp0 = 0, ndp1 = 0;
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) {
            ndp0 += dp0;
            ndp1 += dp1;
        }

        if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) {
            ndp0 += dp1;
            ndp1 += dp0;
        }

        dp0 = ndp0 % MOD;
        dp1 = ndp1 % MOD;
    }

    cout << (dp0 + dp1) % MOD << endl;
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