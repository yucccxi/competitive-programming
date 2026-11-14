#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    if (t == 0) {
        cout << 0 << endl;
        return;
    }

    vector<ll> coef(6);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            ll pw = 1;
            for (int k = 1; k <= j; k++) {
                pw *= b[i];
            }
            coef[j] += a[i] * pw * ((j & 1) ? +1 : -1);
        }
    }

    for (int i = 1; i < t; i++) {
        if (coef[i] != 0) {
            cout << "infinity" << endl;
            return;
        }
    }

    cout << coef[t] / t << endl;
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