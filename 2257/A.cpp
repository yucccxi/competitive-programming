#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    vector<string> b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    bool seen[26] {};
    for (int i = 1; i <= n; i++) {
        seen[a[i][0] - 'a'] = true;
    }

    for (int i = 1; i <= m; i++) {
        for (char ch : b[i]) {
            if (!seen[ch - 'A']) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
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