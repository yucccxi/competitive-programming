#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int k; cin >> k;
    vector<int> a(k + 1);
    int cnt[4] = {0};
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        if (a[i] >= 3) {
            cnt[3]++;
        } else cnt[a[i]]++;
    }

    if (cnt[3] > 0) {
        cout << "YES" << endl;
    } else if (cnt[2] > 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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