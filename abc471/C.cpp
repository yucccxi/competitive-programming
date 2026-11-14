#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    int lo = lower_bound(a.begin(), a.end(), 0) - a.begin() - 1;
    int hi = lo + 1;

    ll pos = 0;
    ll ans = 0;
    while (lo >= 0 || hi < n) {
        if (lo == -1 || hi == n) {
            if (lo == -1) {
                ans += abs(a[hi] - pos);
                pos = a[hi++];
            } else {
                ans += abs(a[lo] - pos);
                pos = a[lo--];
            }
        } else {
            if (abs(a[lo] - pos) <= abs(a[hi] - pos)) {
                ans += abs(a[lo] - pos);
                pos = a[lo--];
            } else {
                ans += abs(a[hi] - pos);
                pos = a[hi++];
            }
        }
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