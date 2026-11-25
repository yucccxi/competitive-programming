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

    stack<int> stk;
    vector<int> L(n + 1, 0), R(n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        while (stk.size() > 0 && a[stk.top()] > a[i]) {
            stk.pop();
        }
        if (stk.size() > 0) {
            L[i] = stk.top();
        }
        stk.push(i);
    }

    while (stk.size() > 0) stk.pop();

    for (int i = n; i >= 1; i--) {
        while (stk.size() > 0 && a[stk.top()] > a[i]) {
            stk.pop();
        }
        if (stk.size() > 0) {
            R[i] = stk.top();
        }
        stk.push(i);
    }


    // for (int i = 1; i <= n; i++) {
    //     cout << L[i] << " " << R[i] << endl;
    // }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (L[i] != i - 1 && R[i] != i + 1) {
            ans += 2;
        } else if (L[i] == i - 1 && R[i] == i + 1) {
            ans += 1;
        } else {
            ans += R[i] - L[i] - 1;
        }

        // cout << i << " " << ans << endl;
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