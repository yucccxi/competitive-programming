#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;

    ll ans = 0;

    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
            ans += abs(a[i][j]);
    	}
    }

    vector<ll> rem(m + 1);
    for (int i = 1; i <= n; i++) {
        int pos = 0;
        for (int j = 1; j <= m; j++) {

            if (rem[j] > 0 || a[i][j] > 0) {
                pos = j;
            }

            if (a[i][j] > 0) {
                rem[j] += a[i][j];
            } else if (a[i][j] < 0) {
                ll cur = -a[i][j];
                while (pos > 0 && cur > 0) {
                    ll used = min(cur, rem[pos]);
                    cur -= used;
                    rem[pos] -= used;

                    ans -= used * 2;

                    if (rem[pos] == 0) {
                        --pos;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}