#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int geti(char c) {
    int k = c - 'a';
    if (c <= 'o') {
        return 2 + k / 3;
    } else if (c <= 's') {
        return 7;
    } else if (c <= 'v') {
        return 8;
    }

    return 9;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        cout << geti(s[0]);
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