#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    s = '.' + s, t = '.' + t;
    int cnt0[2] = {};
    int cnt1[2] = {};

    for (int i = 1; i <= n; i += 2) {
        if (s[i] == '1') cnt0[0]++;
        if (t[i] == '1') cnt0[1]++;
    }

    for (int i = 2; i <= n; i += 2) {
        if (s[i] == '1') cnt1[0]++;
        if (t[i] == '1') cnt1[1]++;
    }

    if (cnt0[0] + cnt1[0] != cnt0[1] + cnt1[1]) {
        cout << "NO" << endl;
        return;
    }

    if (cnt0[0] != cnt0[1]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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