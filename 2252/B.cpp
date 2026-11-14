#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = '.' + s;

    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            cnt0++;
        } else {
            cnt1++;
        }
    }

    int mx = -1;

    char prev = '0';
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] != prev) {
            prev = s[i];
            cnt++;
        }

        int c1 = (cnt + 1) / 2;
        int c0 = (cnt + 0) / 2;

        if (abs((cnt0 - c0) - (cnt1 - c1)) <= 1) {
            mx = max(mx, cnt);
        }
    }

    prev = '1';
    cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] != prev) {
            prev = s[i];
            cnt++;
        }

        int c0 = (cnt + 1) / 2;
        int c1 = (cnt + 0) / 2;

        if (abs((cnt0 - c0) - (cnt1 - c1)) <= 1) {
            mx = max(mx, cnt);
        }
    }

    cout << (mx == -1 ? -1 : n - mx) << endl;
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