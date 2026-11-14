#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {

    const int M = 1e9;

    int q; cin >> q;
    vector<ll> cand;
    for (int i = 0; i <= 40; i++) {
        ll x = i * i * i;
        ll cand0 = x << 1;
        ll cand1 = cand0 | 1;
        if (__builtin_popcount(cand0) == i) {
            cand.push_back(cand0);
        }

        if (__builtin_popcount(cand1) == i) {
            cand.push_back(cand1);
        }
    }

    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    while (q--) {
        ll x; cin >> x;
        auto it = lower_bound(cand.begin(), cand.end(), x);
        if (it == cand.end() || *it > M) {
            cout << -1 << endl;
        } else {
            cout << *it << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}