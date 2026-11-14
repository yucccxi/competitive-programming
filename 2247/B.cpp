#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    if (k > m) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<int> t;
    for (int i = 1; i <= k - 1; i++) {
        t.push_back(1);
    }

    t.push_back(m - (k - 1));

    for (int i = 0; i < n; i++) {
        cout << t[i % t.size()] << " ";
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