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

    map<int, vector<int>> mp;
    for (int i = 1; i <= n - 4; i++) {
        int v = a[i] + a[i + 2] - a[i + 4];
        mp[v].push_back(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n - 4; i++) {
        int v = a[i] + a[i + 2] - a[i + 4];
        auto &vec = mp[v];
        int m = vec.size();
        int idx = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
        int rem = m - idx - 1;
        for (int j = idx + 1; j < m && vec[j] <= i + 4; j++) {
            if (vec[j] == i + 2 || vec[j] == i + 4) {
                --rem;
            }
        }

        ans += rem;
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