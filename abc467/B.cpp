#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;

        string s; cin >> s;
        if (s == "keep") {
            ans += v - u;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}