#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    ll x, y;
    cin >> y >> x;
    ll n = x + y;
    ll len = n / (x + 1);
    ll rem = n - len * (x + 1);
    ll ans = n * n - len * len * (x + 1 - rem) - (len + 1) * (len + 1) * rem;
    ans /= 2;
    cout << ans << endl;
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