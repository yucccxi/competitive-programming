#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<__int128> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
        ll p, q, r;
        cin >> p >> q >> r;
        a[i] = p, b[i] = q, c[i] = r;
    }

    auto check = [&](__int128 S) -> bool {
        __int128 tot = 0;
        for (int i = 1; i <= n; i++) {
            __int128 sm = a[i] + b[i] + c[i];
            
            if (sm >= S) {
                continue;
            }
            
            if (a[i] == b[i] && b[i] == c[i]) {
                return false;
            }
            
            __int128 ops = 0;
            if (a[i] > b[i] || a[i] > c[i] || b[i] > c[i]) {
                ops = S - sm;
            } else {
                __int128 costA = (__int128)3e30, costB = (__int128)3e30;
                
                if (a[i] < b[i]) {
                    __int128 steps = c[i] - b[i] + 1;
                    __int128 nsm = a[i] + 2 * b[i] - 1;
                    costA = steps + max((__int128)0, S - nsm);
                }
                
                if (a[i] < c[i]) {
                    __int128 steps = b[i] - a[i] + 1;
                    __int128 nsm = 2 * a[i] + c[i] - 1;
                    costB = steps + max((__int128)0, S - nsm);
                }
                
                ops = min(costA, costB);
            }
            
            tot += ops;
            if (tot > k) {
                return false;
            }
        }
        
        return tot <= k;
    };

    __int128 l = -9e18, r = 9e18;
    while (l <= r) {
        __int128 mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << (ll)r << endl;
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