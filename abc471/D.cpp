#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int q, v;
    cin >> q >> v;
    priority_queue<int> pq;
    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            int t, w;
            cin >> t >> w;
            pq.push(w - t);
        } else {
            int t; cin >> t;

            if (pq.size() == 0) {
                cout << -1 << endl;
                continue;
            }

            int mx = pq.top(); pq.pop();
            cout << min(v, mx + t) << endl;
        }
    }
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