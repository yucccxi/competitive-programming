#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    int st = -1, ed = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (st == -1) st = i;
            ed = i;
        }
    }

    int cnt0 = 0;
    for (int i = 0; i < st; i++) {
        if (s[i] == '(') cnt0++;
        else cnt0--;
    }

    int cnt1 = 0;
    for (int i = ed + 1; i < n; i++) {
        if (s[i] == ')') cnt1++;
        else cnt1--;
    }

    
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