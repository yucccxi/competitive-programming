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

    auto calc = [&]() -> ll {
        if (n == 1) return a[1];

        vector<ll> pref(n + 1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + a[i];
        }

        ll ans = LINF;

        for (int i = 1; i < n; i++) {
            ll go   = pref[i - 1];
            ll back = pref[i];
            ll cnt  = n - i;
            ans = min(ans, go + back + cnt * (a[i] + a[i + 1]));
        }
        
        return ans;
    };

    ll cand = calc();

    int l = 2, r = n;
    while (l < r) {
        swap(a[l], a[r]);
        l++, r--;
    }

    cand = min(cand, calc());

    cout << cand << endl;
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