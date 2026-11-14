#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2);
    vector<int> b(m + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    int p = 1, q = 1;
    while (p <= n && q <= m) {
        int take = min(a[p] - a[p + 1], b[q] - b[q + 1]);
        a[p] -= take, b[q] -= take;
        
        b[q] -= 1;
        if (b[q] < b[q + 1]) {
            q++;
        }

        if (q == m + 1) break;

        a[p] -= 1;
        if (a[p] < a[p + 1]) {
            p++;
        }

        if (p == n + 1) break;
    }

    if (p == n + 1) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
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