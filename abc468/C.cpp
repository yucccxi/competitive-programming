#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> p(n), q(n);
    for (int &x : p) cin >> x;
    for (int &x : q) cin >> x;

    if (p >= q) {
        cout << 0 << endl;
        return;
    }

    int cnt = 0;
    while (next_permutation(p.begin(), p.end())) {
        if (p < q) {
            cnt++;
        } else break;
    }

    cout << cnt << endl;
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