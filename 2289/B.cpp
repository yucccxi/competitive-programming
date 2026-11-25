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

    vector<pair<int, int>> intv;
    int l = 1;
    while (l <= n) {
        int r = l;
        while (r <= n && a[l] == a[r]) {
            ++r;
        }

        intv.push_back({l, r - 1});

        l = r;
    }

    int ans = 0;

    for (int i = 1; i <= k; i++) {
        int l = i, r = n - k + i;
        pair<int, int> p = {l, 2e9};
        int pos = upper_bound(intv.begin(), intv.end(), p) - intv.begin();
        // cout << l << " " << r << endl;
        if (pos == 0) continue;
        --pos;

        if (intv[pos].second >= r) {
            ++ans;
        }
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