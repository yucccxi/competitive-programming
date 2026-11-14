#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> diff(n + 2);
    for (int i = 1; i <= n; i++) {
        if (b[i] > 0) {
            int L = max(1, i - b[i] + 1);
            int R = min(n, i + b[i] - 1);
            if (L <= R) {
                diff[L    ]++;
                diff[R + 1]--;
            }
        }
    }

    vector<bool> allowed(n + 1, false);
    int covered = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        covered += diff[i];
        if (covered == 0) {
            allowed[i] = true;
            cnt++;
        }
    }

    if (cnt == 0) {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] != -1) {
            bool ok = false;
            if (i - b[i] >= 1 && allowed[i - b[i]]) ok = true;
            if (i + b[i] <= n && allowed[i + b[i]]) ok = true;

            if (!ok) {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << allowed[i];
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