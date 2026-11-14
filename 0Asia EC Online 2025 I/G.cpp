#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> pairs(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        pairs[i] = {u, v};
    }

    sort(pairs.begin(), pairs.end());

    int s = 1;
    for (auto &[u, v] : pairs) {
        if (u == s && v == s + 1) s++;
    }

    cout << (s == n ? "Yes" : "No") << endl;
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