#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    string s; cin >> s;
    s = '.' + s;

    vector<int> pref(n + 1);
    for (int i = 2; i <= n; i++) {
        if (s[i] == s[i - 1]) pref[i]++;
        pref[i] += pref[i - 1];
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        int cnt = (pref[r] - pref[l] + 1) / 2;

        cout << (cnt <= k ? "YES" : "NO") << endl;
    }
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