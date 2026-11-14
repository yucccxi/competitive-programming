#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e5 + 5;

int n, p;
int lb[MAXN], rb[MAXN], cnt[MAXN];

double ans;

void solve() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        lb[i] = l, rb[i] = r;
        cnt[i] = r / p - (l - 1) / p;
        cnt[i] = (r - l + 1) - cnt[i];
    }

    lb[n + 1] = lb[1];
    rb[n + 1] = rb[1];
    cnt[n + 1]  = cnt[1];

    for (int i = 1; i <= n; i++) {
        ans += 2000 * (1 - (double)cnt[i] * cnt[i + 1] / (rb[i] - lb[i] + 1) / (rb[i + 1] - lb[i + 1] + 1));
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}