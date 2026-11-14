#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> cnt(n + 1, vector<int>(4));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }

        cnt[i][a[i]]++;
    }

    vector<int> suffmx(n, n - 1);
    for (int i = n - 2; i >= 1; i--) {
        suffmx[i] = suffmx[i + 1];
        if (cnt[i][1] + cnt[i][2] - cnt[i][3] > cnt[suffmx[i]][1] + cnt[suffmx[i]][2] - cnt[suffmx[i]][3]) {
            suffmx[i] = i;
        }
    }

    for (int i = 1; i <= n - 2; i++) {
        if (cnt[i][1] < cnt[i][2] + cnt[i][3]) {
            continue;
        }

        int j = suffmx[i + 1];

        if (cnt[j][1] + cnt[j][2] - cnt[j][3] >= cnt[i][1] + cnt[i][2] - cnt[i][3]) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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