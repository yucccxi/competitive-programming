#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int MOD = 998244353;

const int MAXN = 25;

int n;
int a[MAXN], pre[MAXN];
ll dp[1 << MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int inversions = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] > a[i]) {
                inversions++;
                pre[a[j] - 1] |= (1 << (a[i] - 1));
            }
        }
    }

    if (inversions == 0) {
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = (ans * i) % MOD;
        }

        cout << ans << endl;
        return;
    }

    dp[0] = 1;
    for (int s = 0; s < (1 << n); s++) {
        for (int v = 0; v < n; v++) {
            if (s >> v & 1) continue;
            if ((s & pre[v]) == pre[v]) {
                dp[s | (1 << v)] += dp[s];
                dp[s | (1 << v)] %= MOD;
            }
        }
    }

    cout << (dp[(1 << n) - 1] << 1) % MOD << endl;
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