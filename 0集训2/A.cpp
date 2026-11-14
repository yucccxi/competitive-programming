#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;

    vector<pair<int, int>> coords(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> coords[i].first >> coords[i].second;
    }

    sort(coords.begin() + 1, coords.end(), [&](const auto &p1, const auto &p2) -> bool {
        ll l = (p1.first - p1.second) - (p2.first - p2.second);
        ll r = (p1.first + p1.second) - (p2.first + p2.second);
        if (l != 0) return l < 0;
        return r > 0;
    });

    ll ans = 0;

    ll rb = coords[1].first + coords[1].second;
    for (int i = 1; i <= n; i++) {
        auto &[mid, r] = coords[i];
        ans += max(0LL, mid - r - rb);
        rb = max(rb, 0LL + mid + r);
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