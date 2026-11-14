#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<ll> y(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }

    ll totx = 0, toty = 0, totx2 = 0;
    ll totxy = 0;

    for (ll x = 1; x <= n; x++) {
        totx += x;
        toty += y[x];
        totx2 += x * x;
        totxy += x * y[x];
    }

    double w = ((double)n * totxy - (double)totx * toty) / ((double)n * totx2 - (double)totx * totx);
    double b = (toty - w * totx) / n;

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += ((w * i + b) - y[i]) * ((w * i + b) - y[i]);
    }

    cout << fixed << setprecision(12) << ans << endl;
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