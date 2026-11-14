#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;

    ll cur = 0, popc = 0;
    for (int i = 0; i < 30; i++) {
        int b = 1 << i;

        if (cur + (ll)b * k <= n) {
            popc += k;
            cur += b * k;
            continue;
        } else {
            for (int j = 0; j < k && cur + b <= n; j++) {
                popc++;
                cur += b;
            }

            break;
        }
    }

    cout << popc << endl;
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