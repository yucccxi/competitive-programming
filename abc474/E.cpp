#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> all(n + 1);
    int mna = INF;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        all[i] = {a, a - b};
        mna = min(mna, a);
    }

    auto cmp = [&](const int &i, const int &j) -> bool {
        return all[i].second < all[j].second;
    };

    int cnt = n;

    ll cur = 0;
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 1; i <= n; i++) {
        pq.push(i);
        cur += all[i].first;
    }

    ll ans = cur;

    while (pq.size() > 0) {
        int x = pq.top();
        pq.pop();
        cur -= all[x].second;
        
        if (cnt >= 2) {
            cnt -= 2;
        } else {
            cur += (2 - cnt) * mna;
            cnt = 0;
        }

        ans = min(ans, cur);
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