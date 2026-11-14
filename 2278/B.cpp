#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    
    int total = x + y + z;
    char move;
    
    if (x >= y && x >= z) {
        move = 'P';
    } else if (y >= x && y >= z) {
        move = 'R';
    } else {
        move = 'S';
    }
    
    string ans(total, move);

    cout << ans << endl;
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