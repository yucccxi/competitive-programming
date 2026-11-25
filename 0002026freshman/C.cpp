#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;

    auto check = [&](ll val) -> bool {
        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min((ll)n, val / i);
        }
        return cnt < ((ll)n * n + 1) / 2;
    };

    ll l = 1, r = (ll)n * n;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << l << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}