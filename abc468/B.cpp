#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int m, d;
    string s;
    cin >> m >> d;
    cin >> s;
    vector<int> a(m + 1);
    for (int i = 0; i < m; i++) {
        if (s[i] == '.') continue;
        a[max(0, i - d)]++;
        a[min(m, i + d + 1)]--;
    }

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        a[i] += a[i - 1];
        cnt += (a[i] == 0);
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