#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, t;
    cin >> n >> t;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int step = 0; step < t; step++) {
        int best = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[best]) best = i;
        }
        cout << best + 1 << endl;

        ll v = a[best];
        a[best] = 0;
        if (n == 1) continue;

        ll inc = v / (n - 1);
        ll rem = v % (n - 1);
        for (int i = 0; i < n; i++) {
            if (i != best) a[i] += inc;
        }

        for (int i = 0; i < n && rem > 0; i++) {
            if (i == best) continue;
            a[i]++;
            rem--;
        }
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