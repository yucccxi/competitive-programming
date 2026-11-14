#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), lim(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++) {
        cin >> lim[i];
    }

    auto check = [&](ll d) -> bool {
        ll L = a[1] - d, R = a[1] + d;

        for (int i = 2; i <= n; i++) {
            ll lb = a[i] - d, rb = a[i] + d;

            ll nL = min(rb, R - lim[i]);
            ll nR = max(lb, L + lim[i]);

            bool okL = (lb <= nL);
            bool okR = (nR <= rb);

            if (!okL && !okR) {
                return false;
            }

            L = okL ? lb : nR;
            R = okR ? rb : nL;
        }

        return true;
    };

    ll l = 0, r = 1e18;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;
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