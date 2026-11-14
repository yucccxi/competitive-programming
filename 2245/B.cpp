#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;

    sort(a.begin() + 1, a.end());
    int l = 1, r = n;
    while (l < r) {
        ans -= c;
        ans += a[r];
        if (a[l] >= c) {
            ans -= c;
            ans += a[l];
        }

        l++, r--;
    }

    if (l == r) {
        ans += a[l] - c;
    }

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