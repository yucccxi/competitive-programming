#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> m >> n;
    vector<pair<int, int>> intervals(m + 1);
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        intervals[i] = {l, r};
    }

    sort(intervals.begin() + 1, intervals.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    int cnt = 0;

    int curx = 1;
    int idx = 1;
    while (idx <= m || pq.size() > 0) {
        if (pq.size() == 0) {
            curx = intervals[idx].first;
        }

        while (idx <= m && intervals[idx].first == curx) {
            pq.push(intervals[idx].second);
            idx++;
        }

        int r = pq.top();
        pq.pop();
        if (curx < r) {
            ++cnt;
            ++curx;
        }
    }

    cout << n - cnt << endl;
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