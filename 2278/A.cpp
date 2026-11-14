#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    int cnts[26] = {}, cntt[26] = {};
    for (char c : s) {
        cnts[c - 'a']++;
    }

    for (char c : t) {
        cntt[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnts[i] < cntt[i]) {
            cnts[i] -= cntt[i];
        }
    }
    
    int target[26] = {};
    target['s' - 'a'] = 1;
    target['i' - 'a'] = 1;
    target['x' - 'a'] = 1;

    for (int i = 0; i < 26; i++) {
        if (cnts[i] - cntt[i] != target[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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