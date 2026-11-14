#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    // 5, 10
    int n, q;
    cin >> n >> q;

    int ans = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 3 == 0 || a[i] == 5 || a[i] == 10) {
            ans++;
        }
    }

    cout << ans << " ";
    while (q--) {
        int p, x;
        cin >> p >> x;
        if (a[p] % 3 == 0 || a[p] == 5 || a[p] == 10) {
            ans--;
        }

        a[p] = x;

        if (a[p] % 3 == 0 || a[p] == 5 || a[p] == 10) {
            ans++;
        }

        cout << ans << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // vector<int> b = {0, 3, 5, 6, 9, 10, 12, 15};

    // for (int x : b) {
    //     cout << (5 ^ x) << " " << (10 ^ x) << endl;
    // }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}