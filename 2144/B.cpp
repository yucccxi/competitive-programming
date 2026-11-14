#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt0 = 0, pos = 0;
    vector<bool> seen(n + 1);
    for (int i = 1; i <= n; i++) {
        seen[a[i]] = true;
        if (a[i] == 0) { cnt0++; pos = i; }
    }

    if (cnt0 == 1) {
        for (int i = 1; i <= n; i++) {
            if (!seen[i] && pos == i) {
                a[i] = i;
            }
        }
    }

    int l = 1, r = n;
    while (l <= r && a[l] == l) l++;
    while (l <= r && a[r] == r) r--;

    cout << r - l + 1 << endl;
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