#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

mt19937 rng(random_device{}());

ll solve0(ll n, ll d, ll s) {
    n = min(n, 2 * d);
    if (s > d) return s;
    ll mx = n / s;
    ll cnt = d / s;

    auto spf = [&](ll x) -> ll {
        for (ll i = 2; i * i <= x; i++) {
            if (x % i == 0) return i;
        }
        return x;
    };

    auto check = [&](ll x) -> bool {
        ll f = spf(x);
        if (f == x) return x - 1 <= cnt;
        return (f - 1) * (x / f) <= cnt;
    };

    if (check(mx)) {
        return mx * s;
    } else {
        return (mx - 1) * s;
    }
}

ll solvebrute(ll n, ll d, ll s) {
    if (s > d) return s;

    vector<int> dp(n + 1);
    for (int i = n; i >= 1; i--) {
        if (i > d) {
            dp[i] = i;
        } else if (2 * i > n) {
            dp[i] = i;
        } else {
            for (int j = 1; (j + 1) * i <= n && j * i <= d; j++) {
                dp[i] = max(dp[i], dp[(j + 1) * i]);
            }
        }
    }

    return dp[s];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, d, s;

    int c = 0;

    while (true) {
        n = rng() % 999999 + 2;
        d = rng() % (n - 1) + 1;
        s = rng() % n + 1;

        // n = 729613, d = 529804, s = 51511;

        ll ans = solvebrute(n, d, s);
        // ll sna = solve0(n, d, s);
        cout << "Sample for N=" << n << "(" << min(n, 2 * d) << ")" << ", D=" << d << ", S=" << s << endl;
        cout << "ans: " << ans << endl;
        cout << "max:  " << n / s  << "(" << min(n, 2 * d) / s << ")" << endl;
        cout << "real: " << ans / s << endl;
        // cout << sna << endl;

        cout << "abs: " << abs(min(n, 2 * d) / s - ans / s) << endl;

        break;
    }

    // while (true) {
    //     n = rng() % 9999 + 2;
    //     d = rng() % (n - 1) + 1;
    //     s = rng() % n + 1;

    //     cout << "Sample for N=" << n << ", D=" << d << ", S=" << s << endl;

    //     ll brute = solvebrute(n, d, s);
    //     ll mine  = solve0(n, d, s);

    //     cout << "Brute: " << brute << ", Your: " << mine << ", ";

    //     if (brute == mine) {
    //         cout << "ok" << endl;
    //     } else {
    //         cout << "no" << endl;
    //         break;
    //     }
    // }

    // cin >> n >> d >> s;

    // int t = 1;
    // while (t--) {
    //     cout << solve0(n, d, s) << endl;
    // }

    return 0;
}