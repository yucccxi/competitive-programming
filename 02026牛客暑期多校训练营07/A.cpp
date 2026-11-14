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

    auto check = [&](int mask) -> bool {
        int pre = 0;
        for (int i = 1; i <= n; i++) {
            int cur = a[i];
            for (int j = 30; j >= 0; j--) {
                if (mask >> j & 1 ^ 1) continue;
                if (cur >> j & 1 ^ 1) {
                    cur |= (1 << j);
                }
            }

            for (int j = 30; j >= 0; j--) {
                if (mask >> j & 1 ^ 1) continue;
                if ((cur ^ (1 << j)) >= pre) {
                    cur ^= (1 << j);
                }
            }

            if (cur < pre) return false;

            pre = cur;
        }

        return true;
    };

    int ans = 0;

    for (int i = 30; i >= 0; i--) {
        int mask = ans | ((1 << i) - 1);
        if (!check(mask)) {
            ans |= (1 << i);
        }
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