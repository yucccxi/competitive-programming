#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int g = 0;
    bool all1 = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        if (a[i] != 1) {
            all1 = false;
        }
    }

    if (g > 1) {
        cout << 1 << endl;
        cout << g << " " << 1 << endl;
        return;
    }
    
    cout << 2 << endl;
    cout << 4 << " " << 2 << endl;
    cout << 4 << " " << 2 << endl;
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