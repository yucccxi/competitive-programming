#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int l, r;
    cin >> l >> r;

    int sm = 0;
    for (int i = l; i <= r; i++) {
        sm += i;
    }

    int cnt = 1000;

    if (sm >= l && sm <= r) {
        cnt = 0;
    }

    for (int cur = sm, i = l; i <= r; i++) {
        cur -= i;
        if (cur >= i + 1 && cur <= r) {
            cnt = min(cnt, i - l + 1);
        }
    }

    for (int cur = sm, i = r; i >= l; i--) {
        cur -= i;
        if (cur <= i - 1 && cur >= l) {
            cnt = min(cnt, r - i + 1);
        }
    }

    cout << cnt << endl;
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