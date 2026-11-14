#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXV = 3e5 + 5;

int spf[MAXV];

void sieve() {
    for (int i = 1; i < MAXV; i ++) spf[i] = i;
    for (int i = 2; i < MAXV; i ++) {
        if (spf[i] == i) {
            for (ll j = (ll)i * i; j < MAXV; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> pf;
    {
        int v = x;
        while (v > 1) {
            int p = spf[v];
            pf.push_back(p);
            while (spf[v] == p) {
                v /= p;
            }
        }
    }

    map<int, ll> mp;

    for (int i = 1; i <= n; i++) {
        for (int p : pf) {
            if (a[i] % p == 0) {
                mp[p] += a[i];
            }
        }
    }

    ll ans = 0;
    for (auto &[k, v] : mp) {
        ans = max(ans, v);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    sieve();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}