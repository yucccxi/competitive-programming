#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 305;
const int MOD = 1e9 + 7;

int n, q;
string s;

ll dp[3][MAXN][MAXN][MAXN];

void solve() {
    cin >> n >> q >> s;
    s = '.' + s;

    int cnt = 0;

    if (s[1] == '?') {
        cnt = 1;
        dp[0][1][1][0] = 1;
        dp[1][1][0][1] = 1;
        dp[2][1][0][0] = 1;
    } else {
        dp[s[1] - 'a'][1][0][0] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        bool unknown = (s[i] == '?');

        for (int prev = 0; prev < 3; prev++) {
            for (int a = 0; a <= cnt; a++) {
                for (int b = 0; a + b <= cnt; b++) {
                    ll ways = dp[prev][i - 1][a][b];
                    if (ways == 0) continue;

                    for (int cur = 0; cur < 3; cur++) {
                        if (cur == prev) continue;
                        if (!unknown && cur != s[i] - 'a') continue;

                        int na = a + (unknown && cur == 0);
                        int nb = b + (unknown && cur == 1);

                        ll &to = dp[cur][i][na][nb];
                        to += ways;
                        if (to >= MOD) to -= MOD;
                    }
                }
            }
        }

        if (unknown) cnt++;
    }

    for (char ch = 'a'; ch <= 'c'; ch++) {
        for (int a = 0; a <= 300; a++) {
            for (int b = 1; b <= 300; b++) {
                dp[ch - 'a'][n][a][b] += dp[ch - 'a'][n][a][b - 1];
                dp[ch - 'a'][n][a][b] %= MOD;
            }
        }
    }

    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        ll ans = 0;
        for (char ch = 'a'; ch <= 'c'; ch++) {
            for (int i = 0; i <= min(a, cnt); i++) {
                int l = max(0, cnt - i - c);
                int r = min(b, cnt - i);
                if (l > r) continue;

                if (l == 0) ans += dp[ch - 'a'][n][i][r];
                else        ans += dp[ch - 'a'][n][i][r] - dp[ch - 'a'][n][i][l - 1];
                ans = (ans % MOD + MOD) % MOD;
            }
        }

        cout << ans << endl;
    }
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