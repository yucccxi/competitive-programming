#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int cross(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}

void solve() {
    int n; cin >> n;
    vector<int> xs(n + 2), ys(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        cin >> xs[i] >> ys[i];
    }

    int ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (cross(xs[i + 1] - xs[i], ys[i + 1] - ys[i], 
                xs[i + 2] - xs[i + 1], ys[i + 2] - ys[i + 1]
            ) > 0
        ) {
            ans++;
        }
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