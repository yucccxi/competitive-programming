#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;

    ll cnts[2]  = {};
    ll cntt[2]  = {};
    ll cntst[2] = {};

    for (int i = 0; i < n; i++) {
        int u = s[i] - '0';
        int v = t[i] - '0';
        cnts[u]++, cntt[v]++, cntst[u ^ v]++;
    }

    ll ans = 0;

    if (k & 1) {
        ll cnt = ((1 << k) + 1) / 3;
        ans = cnt * (cnts[0] * cnts[1] + cntt[0] * cntt[1] + cntst[0] * cntst[1]);
    } else {
        ll cnt = ((1 << k) - 1) / 3;
        ans = cnt * (cnts[0] * cnts[1] + cntt[0] * cntt[1] + cntst[0] * cntst[1]);
        ans += cnts[0] * cnts[1] + cntt[0] * cntt[1];
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