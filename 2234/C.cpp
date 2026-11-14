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

    for (int i = 1; i <= n; i++) {
        vector<int> height(n + 1);

        int cur = i;
        int prev = -1;
        for (int j = 1; j < n; j++) {
            cur = (cur == 1 ? n : cur - 1);
            if (a[cur] > prev) {
                prev = a[cur];
            }

            height[cur] = prev;
        }

        cur = i;
        prev = -1;
        for (int j = 1; j < n; j++) {
            int nxt = (cur == n ? 1 : cur + 1);
            if (a[cur] > prev) {
                prev = a[cur];
            }

            height[nxt] = min(height[nxt], prev);
            cur = nxt;
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += height[i];
        }

        cout << ans << " ";
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