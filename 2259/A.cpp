#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    string s; cin >> s;

    int ans = 0;
    for (int i = 0; i < n / k; i++) {
        bool all1 = true;
        for (int j = i * k; j < (i + 1) * k; j++) {
            if (s[j] == '0') {
                all1 = false;
                break;
            }
        }

        ans += all1;
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