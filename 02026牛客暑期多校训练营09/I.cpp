#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int x, a, b;
    cin >> x >> a >> b;

    if (a == 1) {
        cout << (x + b - 1) / b << endl;
        return;
    }

    int sq;

    {
        int l = 0, r = x;
        while (l <= r) {
            int mid = (l + r) / 2;
            if ((ll)mid * mid <= x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        sq = r;
    }

    ll ans = INF;

    for (int i = 0; i <= 3 * sq; i++) {
        ll u = a, v = a + (i - 1) * (a - 1);
        ll tot = (u + v) * i / 2;
        if (tot >= x) { ans = min(ans, (ll)i); break; }

        ll l = 1, r = x - tot;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll t = min(v, mid);
            ll dmg = (2 * v - 1 - t) * t / 2 + b * mid;
            if (dmg < x - tot) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ans = min(ans, i + l);
    }

    cout << ans << endl;
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