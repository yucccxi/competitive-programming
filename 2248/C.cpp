#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    vector<pair<int, int>> pos(n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (pos[a[i]].first != 0) {
            pos[a[i]].second = i;
        } else pos[a[i]].first = i;
    }

    sort(pos.begin() + 1, pos.end(), [&](const pair<int, int> &p1, const pair<int, int> &p2) -> bool {
        return p1.second - p1.first > p2.second - p2.first;
    });

    ll ans = 0;

    // cout << "---" << endl;

    for (int i = 1; i <= n; i++) {
        auto &[l, r] = pos[i];
        // cout << l << " " << r << endl;
        if (a[l] == -1 && a[r] == -1) continue;
        if (a[l] == -1 || a[r] == -1) { ans++; continue; }
        for (int j = l; j <= r; j++) {
            a[j] = -1;
        }

        ans += (ll)(r - l + 1) * (r - l + 1);
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