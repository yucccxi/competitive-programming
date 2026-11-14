#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = '.' + s, t = '.' + t;
    int pos[26] {};
    for (int i = m - 1; i >= 1; i--) {
        if (pos[t[i] - 'a'] == 0)
            pos[t[i] - 'a'] = i;
    }
    
    int mnlen = INF;
    int mni = 0;
    for (int i = 2; i <= n; i++) {
        int j = pos[s[i] - 'a'];
        if (j > 0) {
            int nlen = i + (m - j);
            if (nlen < mnlen) {
                mnlen = nlen;
                mni = i;
            }
        }
    }
    
    if (mni == 0) {
        cout << -1 << endl;
        return;
    }
    
    for (int i = 1; i <= mni; i++) {
        cout << s[i];
    }
    
    int j = pos[s[mni] - 'a'];
    for (int i = j + 1; i <= m; i++) {
        cout << t[i];
    }
    cout << endl;
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