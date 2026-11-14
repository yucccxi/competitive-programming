#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = '.' + s;

    int segs = 0;

    int l = 1, r = 1;
    while (l <= n) {
        while (r <= n && s[l] == s[r]) {
            r++;
        }

        ++segs;

        l = r;
    }

    int b = 0;
    for (int i = 2; i <= n - 1; i++) {
        if (s[i - 1] != s[i] && s[i] != s[i + 1]) {
            if (s[i - 1] == s[i + 1]) {
                b = 2;
                break;
            } else {
                b = 1;
            }
        }
    }

    cout << segs - b << endl;
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