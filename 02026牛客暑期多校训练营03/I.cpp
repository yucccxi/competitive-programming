#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr ll LINF = 1LL << 60;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll base = 0;
    for (int i = 1; i <= n - 1; i++) {
        base += abs(a[i + 1] - a[i]);
    }

    vector<vector<ll>> c(n + 1, vector<ll>(5, -LINF));
    for (int i = 2; i <= n - 1; i++) {
        ll l = a[i - 1], r = a[i + 1];
        ll old = abs(a[i] - l) + abs(a[i] - r);
        c[i][+2 + 2] = -l - r - old;
        c[i][-2 + 2] = +l + r - old;
        c[i][+0 + 2] = abs(l - r) - old;
    }

    c[1][-1 + 2] = +a[2] - abs(a[1] - a[2]);
    c[1][+1 + 2] = -a[2] - abs(a[1] - a[2]);
    c[n][-1 + 2] = +a[n - 1] - abs(a[n] - a[n - 1]);
    c[n][+1 + 2] = -a[n - 1] - abs(a[n] - a[n - 1]);

    ll maxpref[5][5];
    for (int p = 0; p < 5; p++) {
        for (int q = 0; q < 5; q++) {
            maxpref[p][q] = -LINF;
        }
    }

    for (int p = 0; p < 5; p++) {
        for (int q = 0; q < 5; q++) {
            maxpref[p][q] = max(maxpref[p][q], (p - 2) * a[1] + c[1][q]);
        }
    }

    ll maxgain = -LINF;

    for (int i = 3; i <= n; i++) {
        for (int p = 0; p < 5; p++) {
            for (int q = 0; q < 5; q++) {
                maxgain = max(maxgain, maxpref[p][q] + (q - 2) * a[i] + c[i][p]);
            }
        }

        for (int p = 0; p < 5; p++) {
            for (int q = 0; q < 5; q++) {
                maxpref[p][q] = max(maxpref[p][q], (p - 2) * a[i - 1] + c[i - 1][q]);
            }
        }
    }

    ll ans = max(base, base + maxgain);
    for (int i = 1; i <= n - 1; i++) {
        ll cur = base;
        if (i > 1) {
            cur -= abs(a[i - 1] - a[i]);
            cur += abs(a[i - 1] - a[i + 1]);
        }

        if (i < n - 1) {
            cur -= abs(a[i + 1] - a[i + 2]);
            cur += abs(a[i] - a[i + 2]);
        }

        ans = max(ans, cur);
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