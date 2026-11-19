#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }


    int m; cin >> m;
    while (m--) {
        int l; cin >> l;
        vector<int> b(l + 1);
        for (int i = 1; i <= l; i++) {
            cin >> b[i];
        }

        vector<int> cnt(n + 1);
        cnt[0] = INF;

        for (int i = 1; i <= l; i++) {
            int p = pos[b[i]];
            if (cnt[p - 1] > 0) {
                --cnt[p - 1];
                ++cnt[p];
            }
        }

        cout << cnt[n] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}