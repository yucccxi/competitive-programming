#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(n + 1);
    vector<string> all(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pos[i] >> all[i];
        all[i] = '.' + all[i];
    }

    set<string> v;

    for (int i = 0; i <= n; i++) {
        string ans;
        for (int i = 0; i <= m; i++) {
            ans += '.';
        }

        bool bad = false;

        for (int j = 1; j <= n && !bad; j++) {
            if (j == i) continue;
            int len = all[j].size() - 1;

            for (int k = 1; k <= len; k++) {
                if (ans[pos[j] + k - 1] == '.') {
                    ans[pos[j] + k - 1] = all[j][k];
                } else if (ans[pos[j] + k - 1] != all[j][k]) {
                    bad = true;
                }
            }
        }

        for (int j = 1; j <= m; j++) {
            if (ans[j] == '.') {
                bad = true;
                break;
            }
        }

        if (!bad) v.insert(ans);
    }

    if (v.size() == 0) {
        cout << -1 << endl;
    } else if (v.size() >= 2) {
        cout << -2 << endl;
    } else {
        string ans = *v.begin();
        ans.erase(ans.begin());
        cout << ans << endl;
    }
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