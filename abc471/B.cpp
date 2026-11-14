#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (char &c : s) {
            if (c >= 'A' && c <= 'Z') {
                c -= 'A';
                c += 'a';
            }
        }

        cnt[s]++;
    }

    int ans = 0;
    for (auto &[k, v] : cnt) {
        ans = max(ans, v);
    }
    cout << ans << endl;
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