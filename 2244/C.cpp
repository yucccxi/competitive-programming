#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    int g = __gcd(x, y);
    bool ok = true;
    
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        if ((p - i) % g != 0) {
            ok = false;
        }
    }
    
    cout << (ok ? "YES" : "NO") << endl;
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