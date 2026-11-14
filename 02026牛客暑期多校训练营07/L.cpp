#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    ll n; cin >> n;
    ll ans = 0;
    for (ll b = 1; b * b <= n; b++) {
        ll B = b * (b + 1);
        ll t = (n + 1) / B;
        ans += t * b;
        ll nxt = (t + 1) * B - b; // 最后可能有一段不完整的
        ans += max(0LL, n - nxt + 1);
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