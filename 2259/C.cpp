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

    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            l = i;
            break;
        }
    }

    for (int i = n; i >= 1; i--) {
        if (a[i] == -1) {
            r = i;
            break;
        }
    }

    if (l == 0) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    bool hasl = false;

    for (int i = 1; i < l; i++) {
        if (a[i] == 1) {
            hasl = true;
            break;
        }
    }

    bool hasr = false;

    for (int i = n; i > r; i--) {
        if (a[i] == 1) {
            hasr = true;
            break;
        }
    }

    if (l == r) {
        if (hasl && hasr) {
            a[l] = 0;
        } else {
            a[l] = 1;
        }
    } else {
        a[l] = !hasl;
        a[r] = !hasr;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            a[i] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
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