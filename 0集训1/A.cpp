#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    string ans;

    bool f = true;
    for (int i = 0; i < n - 1; i++) {
        ans.push_back('9');
        f = f && (s[i] == '9');
    }

    if (f) {
        cout << s << endl;
    } else {
        cout << ans << endl;
    }
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