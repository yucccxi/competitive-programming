#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    ll px, py, qx, qy, rx, ry, sx, sy;
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

    if ((py - qy) * (rx - sx) != (ry - sy) * (px - qx)) {
        cout << "Yes" << endl;
        return;
    }

    if (((px + qx) - (rx + sx)) * (qx - px) + ((py + qy) - (ry + sy)) * (qy - py) == 0) {
        cout << "Yes" << endl;
        return;
    }

    cout << "No" << endl;
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