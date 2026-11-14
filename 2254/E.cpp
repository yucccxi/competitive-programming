#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<ll> b(n + 1);
    ll all = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        all += b[i];
    }

    if (all <= 0) {
        cout << -1 << endl;
        return;
    }

    multiset<ll> neg, pos;

    for (int i = 1; i <= n; i++) {
        if (b[i] <= 0) {
            neg.insert(-b[i]);
        } else {
            pos.insert(b[i]);
        }
    }

    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        auto it = neg.lower_bound(tot);
        if (it == neg.begin()) {
            assert(pos.size() > 0);
            tot += *pos.begin();
            pos.erase(pos.begin());
        } else {
            --it;
            tot -= *it;
            neg.erase(it);
        }
        cout << tot << " ";
    }
    cout << endl;
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