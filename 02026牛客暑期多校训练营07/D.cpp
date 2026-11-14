#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

mt19937 rng(random_device{}());

void rd() {
    int n = 8;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    int x = rng() % n + 1;
    cout << n << " " << x << endl;

    for (int i = 1; i <= n; i++) {
        swap(p[i], p[rng() % n + 1]);
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        swap(p[i], p[rng() % n + 1]);
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    rd();

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}