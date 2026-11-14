#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    s = '.' + s, t = '.' + t;
    vector<int> ss(n + 1), tt(n + 1);
    for (int i = 1; i <= n; i++) {
        ss[i] = ss[i - 1] ^ (s[i] - '0');
        tt[i] = tt[i - 1] ^ (t[i] - '0');
    }

    int cntss = accumulate(ss.begin(), ss.end(), 0);
    int cnttt = accumulate(tt.begin(), tt.end(), 0);

    cout << (cntss == cnttt || cntss + cnttt == n + 1 ? "YES" : "NO") << endl;
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