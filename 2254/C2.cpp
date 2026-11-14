#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    s = '.' + s, t = '.' + t;
    
    vector<int> odd[2];
    for (int i = 1; i <= n; i += 2) {
        if (s[i] == '1') odd[0].push_back(i); 
        if (t[i] == '1') odd[1].push_back(i); 
    }

    vector<int> even[2];
    for (int i = 2; i <= n; i += 2) {
        if (s[i] == '1') even[0].push_back(i); 
        if (t[i] == '1') even[1].push_back(i); 
    }

    if (odd[0].size() + even[0].size() != odd[1].size() + even[1].size()) {
        cout << -1 << endl;
        return;
    }

    if (odd[0].size() != odd[1].size()) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0;

    for (int i = 0; i < odd[0].size(); i++) {
        ans += abs(odd[0][i] - odd[1][i]);
    }

    for (int i = 0; i < even[0].size(); i++) {
        ans += abs(even[0][i] - even[1][i]);
    }

    cout << ans / 2 << endl;
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