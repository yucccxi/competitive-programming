#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int INF = 1e9;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    
    if (a != b) {
        cout << "NO" << endl;
        return; 
    }
    
    ll v3 = n;
    v3 = v3 | (v3 << 1);
    v3 = v3 & (v3 << 1);
    
    ll val3 = v3 / n;
    
    ll v4 = n;
    v4 = v4 & (v4 << 1);
    v4 = v4 | (v4 << 1);
    
    ll val4 = v4 / n;
    
    if (val3 > 0 && v3 % n == 0 && (val3 & (val3 - 1)) ==  0 || val4 > 0 && v4 % n == 0 && (val4 & (val4 - 1)) == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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