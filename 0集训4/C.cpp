#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

const int MAXN = 2e5 + 5;
const int MAXK = 2e5 + 5;

int n, m, k, q;
int xs[MAXK], ys[MAXK];

int xm[MAXN], xt[MAXN];

void solveq() {
    for (int i = 1; i <= m; i++) {
        xm[i] = INF;
        xt[i] = INF;
    }

    for (int i = 1; i <= k; i++) {
        xm[ys[i]] = min(xm[ys[i]], xs[i]);
    }

    ll u, d;

    u = 0, d = 1;
    for (int i = 2; i <= m; i++) {
        ll nu = i - 1, nd = xm[i];
        if (u * nd < nu * d) {
            u = nu, d = nd;
        }

        if (u != 0) {
            xt[i] = min((ll)xt[i], ((i - 1) * d + u - 1) / u);
        }
    }

    u = 0, d = 1;
    for (int i = m - 1; i >= 1; i--) {
        ll nu = i - m, nd = xm[i];
        if (d * nu < u * nd) {
            u = nu, d = nd;
        }

        if (u !=  0) {
            xt[i] = min((ll)xt[i], ((m - i) * d - u - 1) / (-u));
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += min(n, xt[i] - 1);
    }

    cout << ans << endl;
}

void solve() {
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++) {
        cin >> xs[i] >> ys[i];
    }

    while (q--) {
        int p, x, y;
        cin >> p >> x >> y;
        xs[p] = x;
        ys[p] = y;

        solveq();
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