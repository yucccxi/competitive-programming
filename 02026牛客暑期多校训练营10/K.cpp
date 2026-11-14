#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll LINF = 1e18;

int a[24][24];
int full;

bool marked[1 << 24];
ll memo[1 << 24];

ll dfs(int mask) {
    if (mask == full) return 0;
    if (marked[mask]) return memo[mask];

    marked[mask] = true;

    int rev = mask ^ full;
    int lsb = rev & -rev;
    int u   = __builtin_ctz(lsb);
    int rem = rev ^ lsb;

    ll ans = -LINF;
    for (int x = rem; x > 0; x &= x - 1) {
        int i = __builtin_ctz(x & -x);
        for (int y = rem; y > x; y &= y - 1) {
            int j = __builtin_ctz(y & -y);
            ans = max(ans, a[i][j] + a[i][u] + a[j][u] + 
                dfs(
                    mask | (1 << u) | (1 << i) | (1 << j)
                ));
        }
    }

    return memo[mask] = ans;
}

void solve() {
    int n; cin >> n;
    full = (1 << (3 * n)) - 1;
    for (int i = 0; i < 3 * n; i++) {
        for (int j = 0; j < 3 * n; j++) {
            cin >> a[i][j];
        }
    }

    cout << dfs(0) << endl;
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