#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

vector<int> cand = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151};

void solve() {
    ll n; cin >> n;
    for (int x : cand) {
        if (x > n) break;
        ll y = n - x;

        if (y % 12 == 0) {
            cout << x << " " << y << endl;
            return;
        }
    }

    cout << -1 << endl;
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