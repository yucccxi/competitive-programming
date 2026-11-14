#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    vector<pair<int, int>> pos(n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (pos[a[i]].first != 0) {
            pos[a[i]].second = i;
        } else pos[a[i]].first = i;
    }

    vector<ll> dp(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        auto &[l, r] = pos[a[i]];
        if (i == l) { dp[i] = dp[i - 1] + 1; continue; }
        dp[i] = max(dp[i - 1] + 1, dp[l - 1] + (ll)(r - l + 1) * (r - l + 1));
    }

    cout << dp[2 * n] << endl;
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