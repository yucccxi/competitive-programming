#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int m, r, c;
    cin >> m >> r >> c;
    if (m >= c) {
        cout << 1.0 << endl;
        return;
    }

    double ans = 0;

    int t = m;
    int cnt = m;
    while (t < c) {
        ans = max(ans, (double)cnt / max(t, c));
        t += m + r;
        cnt += m;
        ans = max(ans, (double)cnt / max(t, c));
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}