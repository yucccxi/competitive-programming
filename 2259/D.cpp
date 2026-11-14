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

    int cnt0 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            cnt0++;
        }
    }

    if (cnt0 == 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    vector<char> ans(n + 1, 0);
    if (cnt0 == 0) {
        for (int i = 1; i <= n; i++) {
            ans[i] = 'A';
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                ans[i] = 'A';
                break;
            }
        }

        for (int i = n; i >= 1; i--) {
            if (a[i] == 0) {
                ans[i] = 'B';
                break;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (ans[i] != 0) continue;
            if (a[i] == 1) {
                ans[i] = 'C';
            } else {
                ans[i] = 'A';
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i]; 
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