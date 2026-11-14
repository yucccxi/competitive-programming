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

    vector<ll> diff(n + 1);
    for (int i = 1; i <= n; i++) {
        diff[i] = a[i] - a[i - 1];
    }

    int l = 2;
    while (l <= n - 1) {
        while (l <= n - 1 && (abs(diff[l]) & 1) != (abs(diff[l + 1]) & 1)) {
            l++;
        }

        if (l == n) break;

        int r = l;
        while (r <= n - 1 && (abs(diff[r]) & 1) == (abs(diff[r + 1]) & 1)) {
            r++;
        }

        sort(diff.begin() + l, diff.begin() + r + 1);

        l = r;
    }

    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        cout << diff[i] << " ";
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