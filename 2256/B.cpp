#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = '.' + s;

    auto check = [&](int st, char c) -> bool {
        for (int i = st; i <= n; i += 2) {
            if (s[i] == '?' || s[i] == '1' + '0' - c) {
                c = '1' + '0' - c;
            } else return false;
        }
        return true;
    };
    
    if ((!check(1, '0') && !check(1, '1')) || (!check(2, '0') && !check(2, '1'))) {
        cout << 0 << endl;
        return;
    } else {
        int ans = 1;
        ans = (check(1, '0') + check(1, '1')) * (check(2, '0') + check(2, '1'));
        cout << ans << endl;
    }
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