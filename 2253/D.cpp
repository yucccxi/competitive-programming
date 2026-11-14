#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

#define int long long

void solve() {
    ll x, y;
    cin >> x >> y;

    ll tot = x + y;
    ll l = 0, r = tot;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if ((1 + mid) * mid / 2 <= tot) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    // r;

    ll tots = r * (r + 1) / 2;

    auto dist = [&](ll p) {
        ll q = tots - p;
        return (x - p) * (x - p) + (y - q) * (y - q);
    };

    ll L = 0, R = tots;

    while (R - L >= 3) {
        ll m1 = L + (R - L) / 3;
        ll m2 = R - (R - L) / 3;
        if (dist(m1) < dist(m2)) {
            R = m2;
        } else {
            L = m1;
        }
    }

    ll bestp = L;
    ll mndist = dist(L);
    for (ll p = L; p <= R; p++) {
        if (dist(p) < mndist) {
            mndist = dist(p);
            bestp = p;
        }
    }

    for (int i = r; i >= 1; i--) {
        if (bestp >= i) {
            cout << 'X';
            bestp -= i;
        } else {
            cout << 'Y';
        }
    }
    cout << endl;
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