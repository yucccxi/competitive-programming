#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll  LINF = 9e18;
const int  INF = 1e9;

void solve() {
    int n, y;
    cin >> n >> y;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];    
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
    }

    if (mx == 1) {
        cout << n << endl;
        return;
    }

    vector<int> cnt(mx + 1);
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    for (int i = 1; i <= mx; i++) {
        cnt[i] += cnt[i - 1];
    }

    ll ans = -LINF;
    for (int x = 2; x <= mx; x++) {
        ll cur = 0;
        for (int p = 1; p <= (mx + x - 1) / x; p++) {
            int l = (p - 1) * x;
            int r = min(mx, p * x);

            int tot  = cnt[r] - cnt[l];
            int prev = cnt[p] - cnt[p - 1];
            int tags = max(0, tot - prev);

            cur += (ll)p * tot - (ll)tags * y;
        }

        ans = max(ans, cur);
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