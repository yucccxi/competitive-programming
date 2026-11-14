#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    string s; cin >> s;
    int n = s.size();

    int ans = 1;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            ++ans;
            break;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
            ans++;
            break;
        }
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