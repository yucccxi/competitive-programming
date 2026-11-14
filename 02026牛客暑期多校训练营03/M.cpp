#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int MOD = 998244353;

void solve() {
    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<int>> T(n + 1);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        T[i].push_back(p);
        T[p].push_back(i);
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