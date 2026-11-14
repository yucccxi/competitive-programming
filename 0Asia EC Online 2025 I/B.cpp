#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

mt19937 rng(random_device{}());

void solve() {
    int n, k;
    cin >> n >> k;

    int len = n - k + 1;

    int s = rng() % len + 1;

    for (int i = s; i <= s + k - 1; i++) {
        cout << i << " ";
    }
    cout << endl;

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