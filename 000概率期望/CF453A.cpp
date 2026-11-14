#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

double ipow(double x, int n) {
    double ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}

void solve() {
    int m, n;
    cin >> m >> n;

    double ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += 1 - ipow((double)(i - 1) / m, n);
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