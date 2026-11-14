#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int a, b;
    cin >> a >> b;
    
    bool f = false;

    f = f || a + b == 9;
    f = f || a - b == 9;
    f = f || a * b == 9;
    f = f || a % b == 0 && a / b == 9;

    cout << (f ? "Nine" : "Nein") << endl;
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