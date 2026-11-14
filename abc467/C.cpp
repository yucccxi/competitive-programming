#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        cin >> b[i];
    }

    int ans = INF;

    for (int k = 0; k <= 1; k++) {
        vector<int> t = a;
        t[n] = k;
        int cur = (t[n] != a[n]);
        for (int i = n - 1; i >= 1; i--) {
            if ((t[i] + t[i + 1]) % m != b[i]) {
                cur++;
                t[i] = (t[i] + 1) % 2;
            }
        }

        ans = min(ans, cur);
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