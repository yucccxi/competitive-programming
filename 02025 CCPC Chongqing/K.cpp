#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (a[1] > 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> comp(n + 1);
    for (int i = 1; i <= n; i++) comp[i] = i;

    auto find = [&](auto &&self, int u) -> int {
        if (u == comp[u]) return u;
        return comp[u] = self(self, comp[u]);
    };

    auto merge = [&](int u, int v) -> bool {
        u = find(find, u), v = find(find, v);
        if (u == v) return false;
        comp[u] = v;
        return true;
    };

    ll ans = m;

    for (int i = 2; i <= n; i++) {
        if (a[i] > 0) merge(i, a[i]);

        vector<int> diff;

        int j = a[i - 1];
        while (j > 0 && j + 1 != a[i]) {
            diff.push_back(find(find, j + 1));
            j = a[j];
        }

        if (a[i] == 0) {
            diff.push_back(find(find, 1));
            sort(diff.begin(), diff.end());
            diff.erase(unique(diff.begin(), diff.end()), diff.end());

            int rem = m - (int)diff.size();
            if (rem <= 0) {
                cout << 0 << endl;
                return;
            }

            ans = (ans * rem) % MOD;
        } else {
            if (j + 1 != a[i]) {
                cout << 0 << endl;
                return;
            }

            int forced = find(find, a[i]);
            sort(diff.begin(), diff.end());
            diff.erase(unique(diff.begin(), diff.end()), diff.end());

            if (binary_search(diff.begin(), diff.end(), forced)) {
                cout << 0 << endl;
                return;
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}