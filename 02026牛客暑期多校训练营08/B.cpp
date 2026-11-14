#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> force;
    bool ok = true;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        force.push_back(x);
        if (x >= 2 * n) {
            ok = false;
        }
    }

    if (!ok) {
        cout << 0 << endl;
        return;
    }

    sort(force.begin(), force.end());

    int l = 0;

    vector<int> dp(n + 1);
    dp[0] = 1;
    ll ans = 0;
    for (int i = 1; i <= 2 * n - 1; i++) {
        while (l < force.size() && force[l] < i) l++;

        if (l == force.size() || force[l] != i) {
            for (int j = n; j >= 1; j--) {
                dp[j] += dp[j - 1];
                if (dp[j] > MOD) dp[j] -= MOD;
            }
        } else for (int j = n; j >= 1; j--) {
            dp[j] = dp[j - 1];
        }

        for (int j = 0; 2 * j < i; j++) {
            dp[j] = 0;
        }
    }

    cout << dp[n] << endl;
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