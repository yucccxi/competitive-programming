#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    string s; cin >> s;
    int n = s.size();

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        int broken = 0;
        while (l >= 0 && r < n) {
            if (s[l] != s[r]) {
                if (broken) break;
                ++broken;
            }

            cnt++;
            l--, r++;
        }
    }

    for (int i = 1; i < n; i++) {
        int l = i - 1, r = i;
        int broken = 0;
        while (l >= 0 && r < n) {
            if (s[l] != s[r]) {
                if (broken) break;
                ++broken;
            }
            cnt++;
            l--, r++;
        }
    }

    cout << cnt << endl;
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