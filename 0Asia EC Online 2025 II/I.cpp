#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// #define endl '\n'

const int MAXN = 1005;
const int MOD  = 998244353;

int n, m;

vector<int> xs, ys;

int query(int c) {
    cout << "?" << " " << 1 << " " << n << " " << c << endl;
    int x; cin >> x;
    return x;
}

ll modpow(ll a, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;
        n >>= 1;
    }

    return ans;
}

ll inv(ll x) {
    return modpow(x, MOD - 2);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
    }

    xs.push_back(0);
    ys.push_back(0);

    for (int i = 1; i < 1000; i++) {
        int y = query(i);
        xs.push_back(i);
        ys.push_back(y);
    }

    cout << "!" << endl;
    int k; cin >> k;

    ll ans = 0;

    for (int i = 0; i < xs.size(); i++) {
        ll li = 1;
        for (int j = 0; j < xs.size(); j++) {
            if (i == j) continue;
            ll term = (((k - xs[j]) % MOD) + MOD) % MOD;
            term = term * inv(((xs[i] - xs[j]) % MOD + MOD) % MOD) % MOD;
            li = (li * term) % MOD;
        }

        ans = (ans + li * ys[i]) % MOD;
    }

    cout << ans << endl;
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