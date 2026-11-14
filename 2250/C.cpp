#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> vl(n + 1), vr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vl[i].first >> vl[i].second;
        cin >> vr[i].first >> vr[i].second;
    }

    int len;
    for (len = n; len >= 0; len--) {
        int cnt = 0;
        for (int i = 1; i <= n && cnt < len; i++) {
            int l = cnt + 1, r = len - cnt;
            if (vl[i].first <= l && l <= vl[i].second) {
                continue;
            }

            if (vr[i].first <= r && r <= vr[i].second) {
                continue;
            }

            cnt++;
        }

        if (cnt == len) break;
    }

    cout << len << endl;
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