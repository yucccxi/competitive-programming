#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int l = 1, r = 1;
    while (l <= n) {
        r = l;
        while (r <= n && a[l] == a[r]) r++;
        pq.push(r - l);
        l = r; 
    }

    ll tot = n;
    ll ans = 0;
    int killed = 0;

    while (pq.size() > 0) {
        int segs = pq.size();
        int tp = pq.top() - killed;

        if (k >= tot && (k - tot) % segs == 0) {
            ans++;
        }

        if (k < tot && (tot - k) % segs == 0 && (tot - k) / segs < tp) {
            ans++;
        }

        int ctp = pq.top();
        while (pq.size() > 0 && pq.top() == ctp) {
            pq.pop();
            tot -= tp; 
        }

        tot -= pq.size() * tp;
        killed += tp;
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