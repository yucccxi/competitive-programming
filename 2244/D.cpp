#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<int> b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(b.begin() + 1, b.end());

    b.erase(unique(b.begin() + 1, b.end()), b.end());

    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    ll ans = pref[n];

    for (int i = b.size() - 1; i >= 1; i--) {
        int l = b[i - 1], r = b[i];
        ll sm = pref[r] - pref[l];
        if (sm < 0) ans -= 2 * sm;
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