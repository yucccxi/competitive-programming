#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using int128 = __int128_t;

#define endl '\n'

const int MOD = 998244353;

struct iint {
    int128 q, r;
};

int128 iterate(vector<iint> &a, ll n, ll m) {
    int128 totq = 0;
    for (int i = 1; i <= n; i++) {
        totq += a[i].q;
    }

    sort(a.begin() + 1, a.end(), [&](const iint &p, const iint &q) -> bool {
        return p.r > q.r;
    });

    int128 used = 0;
    for (int i = 1; i <= n && used < totq; i++) {
        if (m - a[i].r <= totq - used) {
            used += m - a[i].r;
            a[i].r = 0;
            a[i].q++;
        } else {
            a[i].r += totq - used;
            used = totq;
        }
    }

    if (used < totq) {
        int128 inc = (totq - used) / m;
        a[1].q += inc;
        used += inc * m;
        a[1].r += totq - used;
        used = totq;
    }

    for (int i = 1; i <= n && used > 0; i++) {
        int128 t = min((int128)a[i].q, used);
        a[i].q -= t;
        used -= t;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i].r == m - 1) {
            a[i].r = 0;
        }
    }

    assert(used == 0);

    int128 rem = 0;
    for (int i = 1; i <= n; i++) {
        rem += a[i].q;
    }

    return rem == 0;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<iint> a(n + 1);
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        ll q = x / m;
        ll r = x % m;
        a[i] = {q, r};
    }

    if (m == 1) {
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += a[i].q;
            ans %= MOD;
        }

        cout << ans << endl;

        return;
    }

    while (!iterate(a, n, m));

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i].r;
        ans %= MOD;
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