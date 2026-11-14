#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt[3] {};
    for (int i = 1; i <= n; i++) {
        if (a[i] & 1) {
            cnt[1]++;
        } else if ((a[i] / 2) & 1) {
            cnt[2]++;
        } else {
            cnt[0]++;
        }
    }

    cout << max({cnt[0], cnt[1], cnt[2]}) << endl;
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