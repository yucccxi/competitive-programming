#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<vector<int>> T(n + 1);
    for (int i = 2; i <= n; i++) {
        int u; cin >> u;
        T[u].push_back(i);
        T[i].push_back(u);
    }

    int m; cin >> m;
    vector<bool> fuck(n + 1);
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        fuck[x] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (fuck[i]) {
            fuck[i] = false;
            break;
        }
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (fuck[i]) ans.push_back(i);
    }

    cout << ans.size() << " ";
    for (int x : ans) {
        cout << x << " ";
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