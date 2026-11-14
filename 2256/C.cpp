#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    s = '.' + s;
    int cnt[2] {};
    int inc[2] {};
    for (int i = 1; i <= 2 * n; i++) {
        cnt[i & 1] += (s[i] == '1');
        inc[i & 1] += (s[i] == '1' && s[i % (2 * n) + 1] == '0');
    }

    cout << cnt[0] - inc[0] + inc[1] << " " << cnt[1] - inc[1] + inc[0] << endl;
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