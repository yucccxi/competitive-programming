#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll LINF = 9e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> suff(n + 2);
    for (int i = n; i >= 1; i--) {
        suff[i] = suff[i + 1] - a[i];
    }

    vector<ll> pref(n + 1);
    pref[1] = a[1];
    for (int i = 2; i <= n; i++) {
        pref[i] = pref[i - 1] + abs(a[i]);
    }

    ll ans = -LINF;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, pref[i - 1] + suff[i + 1]);
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