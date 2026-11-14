#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = INF;

    for (int k = 0; k <= 20; k++) {

        int cost = k;

        for (int i = 1; i <= n; i++) {

            int mn = INF;

            for (int u = 0; u + k <= 25; u++) {
                int contri = 0;
                int cur = a[i];
                int mask = (1 << (u + k)) - 1;
                int lmask = (1 << k) - 1;

                if ((cur & lmask) > 0) {
                    int c = lmask - (cur & lmask) + 1;
                    contri += c;
                    cur    += c;
                }

                if ((cur & mask) > 0) {
                    int c = mask - (cur & mask) + 1;
                    contri += c;
                    cur    += c;
                }

                cur >>= k;

                if (cur > 0) {
                    contri += 31 - __builtin_clz(cur) + __builtin_popcount(cur);
                }

                mn = min(mn, contri);
            }

            cost += mn;
        }

        ans = min(ans, cost);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // cout << "bits: " << 32 - __builtin_clz(12) << endl;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}