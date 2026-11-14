#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    int p = (n - 1) / 2 + 1;
    int q = n + !(n & 1);

    cout << (ll)p * q << endl;
    for (int i = n; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
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