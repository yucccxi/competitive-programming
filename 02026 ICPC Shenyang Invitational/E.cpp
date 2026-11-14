#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 2e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << (double)a[1] << endl;
        return;
    }

    sort(a.begin() + 1, a.end(), greater<int>());

    double ans = INF;
    for (int i = 1; i <= n - 1; i++) {
        vector<double> cnt(n + 2);
        for (int j = 1; j <= i; j++) {
            cnt[1] += 1;
            cnt[j + 1] -= 1;
        }

        for (int j = i + 1; j <= n; j++) {
            cnt[1] += 0.5;
            cnt[i + 1] -= 0.5;
            cnt[i + 1] += 1;
            cnt[j + 1] -= 1;
        }

        for (int i = 1; i <= n + 1; i++) {
            cnt[i] += cnt[i - 1];
        }

        sort(cnt.begin() + 1, cnt.end() - 1);

        double cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += cnt[i] * a[i];
        }

        ans = min(ans, cur);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(1);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}