#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    s = '.' + s;

    if (s[1] == 'x' || s[n] == 'x') {
        cout << 0 << endl;
        return;
    }

    vector<ll> dp(n + 1), ndp(n + 1);
    dp[1] = 1;
    for (int k = 2; k <= n; k++) {
        fill(ndp.begin(), ndp.end(), 0);

        for (int len = k; len <= n; len++) {
            dp[len] = (dp[len] + dp[len - 1]) % MOD;
        }

        for (int len = k; len <= n; len++) {
            ndp[len] += (dp[len] - dp[len - 1] + MOD) * (len - k + 1) % MOD;
            ndp[len] += 2 * (dp[len - 1] - dp[k - 2] + MOD) % MOD;
            ndp[len] %= MOD;
        }

        if (s[k] == 'x') ndp[k] = 0;
        else for (int len = k + 1; len <= n; len++) {
            ndp[len] = 0;
        }

        dp.swap(ndp);
    }

    cout << dp[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}