#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }

    stable_sort(idx.begin(), idx.end(), [&](const int i, const int j) -> bool {
        return a[i] < a[j];
    });

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int xr = i ^ idx[i];
        if (xr == 0) continue;
        int v = 32 - __builtin_clz(xr) - 1;
        ans = max(ans, 1 << v);
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