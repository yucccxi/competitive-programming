#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 5e3 + 5;
const int MAXLG = 15;

int n;
string s;

int dp[MAXN][MAXN];
pair<int, int> pre[MAXN][MAXN];

int sa[MAXN], rk[MAXN], height[MAXN];
int id[MAXN], cnt[MAXN], oldrk[MAXN], p;

int st[MAXN][MAXLG], lg[MAXN];

void build_suffix_array() {
    int m = 26;

    for (int i = 1; i <= n; i++) {
        rk[i] = s[i] - 'A' + 1;
    }

    for (int i = 1; i <= n; i++) {
        cnt[rk[i]]++;
    }

    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        sa[cnt[rk[i]]--] = i;
    }

    for (int w = 1;; w <<= 1) {
        int p = 0;

        for (int i = n - w + 1; i <= n; i++) {
            id[++p] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (sa[i] > w) {
                id[++p] = sa[i] - w;
            }
        }

        fill(cnt, cnt + m + 1, 0);

        for (int i = 1; i <= n; i++) {
            cnt[rk[i]]++;
        }

        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n; i >= 1; i--) {
            int x = id[i];
            int key = rk[x];

            sa[cnt[key]--] = x;
        }

        for (int i = 1; i <= n; i++) {
            oldrk[i] = rk[i];
        }

        rk[sa[1]] = 1;

        for (int i = 2; i <= n; i++) {
            int x = sa[i - 1];
            int y = sa[i];

            int x1 = oldrk[x];
            int y1 = oldrk[y];

            int x2 = (x + w <= n ? oldrk[x + w] : 0);
            int y2 = (y + w <= n ? oldrk[y + w] : 0);

            bool diff = (x1 != y1 || x2 != y2);

            rk[y] = rk[x] + diff;
        }

        m = rk[sa[n]];

        if (m == n) break;
    }
}

void build_height() {
    int h = 0;
    for (int i = 1; i <= n; i++) {
        int r = rk[i];
        if (r == 1) { height[r] = 0; continue; }
        int j = sa[r - 1];

        while (i + h <= n && j + h <= n && s[i + h] == s[j + h]) {
            h++;
        }

        height[r] = h;

        if (h > 0) --h;
    }
}

void build_st() {
    for (int i = 1; i <= n; i++) {
        st[i][0] = height[i];
    }

    for (int j = 1; j < MAXLG; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int len = lg[r - l + 1];
    return min(st[l][len], st[r - (1 << len) + 1][len]);
}

void solve() {
    cin >> s;
    n = s.size();
    s = '.' + s;

    build_suffix_array();
    build_height();
    build_st();

    auto lprefix = [&](int l1, int r1, int l2, int r2) -> int {
        int mlen = min(r1 - l1 + 1, r2 - l2 + 1);

        int i = rk[l1], j = rk[l2];
        if (i > j) swap(i, j);

        return min(mlen, query(i + 1, j));
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

    for (int i = 2; i < MAXN; i++) {
        lg[i] = lg[i / 2] + 1;
    }

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}