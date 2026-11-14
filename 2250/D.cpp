#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n - 1; i++) {
        cin >> a[i];
    }

    int posl = -1, posr = -1;

    for (int i = 1; i <= n - 1; i++) {
        if (a[i] == n) {
            cout << 0 << endl;
            return;
        }

        if (a[i] == n - 1) {
            if (posl == -1) posl = i;
            posr = i;
        }
    }

    if (posl == -1) {
        cout << 0 << endl;
        return;
    }

    for (int i = posl; i <= posr; i++) {
        if (a[i] != n - 1) {
            cout << 0 << endl;
            return;
        }
    }

    ll ans = 2;

    int l = posl, r = posr;
    for (int i = n - 2; i >= 1; i--) {
        int cnt = n - i;
        int prevl = l, prevr = r;
        while (l > 1     && a[l - 1] == i) --l;
        while (r < n - 1 && a[r + 1] == i) ++r;
        if (l <  prevl && r >  prevr) { ans = 0; break; }
        if (l == prevl && r == prevr) { ans *= (r - l + 2 - cnt); }
        ans %= MOD;
    }

    if (l > 1 || r < n - 1) {
        cout << 0 << endl;
        return;
    }

    cout << ans << endl;
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