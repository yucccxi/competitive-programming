#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    ll cur = 0;
    for (int i = 1; i < k; i++) {
        cur += a[i];
    }

    ll ans = cur;

    for (int i = 1; i <= min(k - 1, n - k + 1); i++) {
        if (i >= k || i <= n - k + 1) {
            ans = min(ans, ans - a[i] + a[n - i + 1]);
        }
    }

    cout << tot - ans << endl;
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