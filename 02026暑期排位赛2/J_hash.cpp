#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 5e3 + 5;

const int B0 = 131, B1 = 13331;
const int M0 = 998244353, M1 = 1000000007;

int n;
string s;

int dp[MAXN][MAXN];
pair<int, int> pre[MAXN][MAXN];

ll hash0[MAXN], hash1[MAXN], pw0[MAXN], pw1[MAXN];

int lcs[MAXN][MAXN];

ll modpow(ll a, ll n, ll m) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return ans;
}

void solve() {
    cin >> s;
    n = s.size();
    s = '.' + s;

    pw0[0] = pw1[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw0[i] = pw0[i - 1] * B0 % M0;
        pw1[i] = pw1[i - 1] * B1 % M1;
        hash0[i] = hash0[i - 1] * B0 + s[i];
        hash0[i] %= M0;
        hash1[i] = hash1[i - 1] * B1 + s[i];
        hash1[i] %= M1;
    }

    auto calchash0 = [&](int l, int r) -> ll {
        ll raw = hash0[r] - hash0[l - 1] * pw0[r - l + 1] % M0 + M0;
        if (raw >= M0) raw -= M0;
        return raw;
    };

    auto calchash1 = [&](int l, int r) -> ll {
        ll raw = hash1[r] - hash1[l - 1] * pw1[r - l + 1] % M1 + M1;
        if (raw >= M1) raw -= M1;
        return raw;
    };

    auto same = [&](int l1, int r1, int l2, int r2) -> bool {
        return calchash0(l1, r1) == calchash0(l2, r2) && calchash1(l1, r1) == calchash1(l2, r2);
    };

    auto lprefix = [&](int l1, int r1, int l2, int r2) -> int {
        int l = 0, r = min(r1 - l1 + 1, r2 - l2 + 1);
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (same(l1, l1 + mid - 1, l2, l2 + mid - 1)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return r;
    };

    dp[1][1]++;
    
    for (int i = 1; i <= n; ++i) {
        
        for (int j = 1; j <= n - i + 1; j++) {
            if (dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                pre[i][j] = pre[i][j - 1];
            }
        }
        
        for (int j = 1; j <= n - i; ++j) {
            if (dp[i][j] == 0) continue;

            int len1 = j, len2 = n - (i + j) + 1;
            int lp = lprefix(i, i + j - 1, i + j, n);

            if (lp < min(len1, len2)) {
                if (s[i + lp] > s[i + j + lp]) {
                    lp = -1;
                }
            } else if (len1 >= len2) {
                lp = -1;
            }

            if (lp == -1) continue;

            ++lp;

            if (dp[i][j] + 1 > dp[i + j][lp]) {
                dp[i + j][lp] = dp[i][j] + 1;
                pre[i + j][lp] = {i, j};
            }
            
            dp[i + j][lp] = max(dp[i + j][lp], dp[i][j] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][n - i + 1]);
    }
    
    cout << ans << endl;
    
    vector<string> all;
    
    int i;
    for (i = n; i >= 1; i--) {
        if (dp[i][n - i + 1] == ans) {
            break;
        }
    }

    pair<ll, ll> empty;

    int u = i, v = n - i + 1;

    while (u != 0 && v != 0) {
        all.push_back(s.substr(u, v));
        auto p = pre[u][v];
        u = p.first, v = p.second;
    }

    for (int i = all.size() - 1; i >= 0; --i) {
        cout << all[i] << endl;
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