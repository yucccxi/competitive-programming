#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int cnt = n + k - 1;
    double split = (double)m / (cnt + 1);

    double ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += m - i * split;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}