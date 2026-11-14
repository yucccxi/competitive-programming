#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;

    const ll L = 2LL * n - 1;

    vector<int> come(m + 1);
    vector<int> alternate(m + 1);
    vector<int> back(m + 1);

    for (int i = 1; i <= n; ++i) {
        ll a;
        cin >> a;

        ll q = a / L;
        ll r = a % L;

        ll x = 2LL * (n - i);
        ll y = 2LL * i - 1;

        ll d = q + 1;

        if (d > m) {
            continue;
        }

        if (r >= x) {
            ++come[d];
        } else if (r < y) {
            ++alternate[d];
        } else {
            ++back[d];
        }
    }

    vector<ll> ans(m + 1);
    ans[1] = n;

    for (int d = 1; d <= m; ++d) {
        if (come[d] != 0) {
            for (int k = 1 + d; k <= m; k += d) {
                ans[k] += come[d];
            }
        }

        if (back[d] != 0) {
            for (int k = d; k <= m; k += d) {
                ans[k] += back[d];
            }
        }

        if (alternate[d] != 0) {
            int p = 2 * d - 1;
            for (int k = d; k <= m; k += p) {
                ans[k] += alternate[d];
            }

            for (int k = 1 + p; k <= m; k += p) {
                ans[k] += alternate[d];
            }
        }
    }

    for (int k = 1; k <= m; ++k) {
        cout << ans[k] << " ";
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