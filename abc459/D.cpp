#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    string s; cin >> s;

    int n = s.size();
    int cnt[26] {};
    for (char c : s) {
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] > (n + 1) / 2) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;

    sort(s.begin(), s.end(), [&](const char &p, const char &q) -> bool {
        int u = cnt[p - 'a'];
        int v = cnt[q - 'a'];
        if (u != v) return u > v;
        return p < q;
    });

    int pos = 0;

    vector<char> ans(n);
    for (int i = 0; i < n; i += 2) {
        ans[i] = s[pos++];
    }

    for (int i = 1; i < n; i += 2) {
        ans[i] = s[pos++];
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;
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