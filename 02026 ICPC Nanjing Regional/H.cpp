#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 4e5 + 5;
const int MOD = 998244353;

ll fac[MAXN], invfac[MAXN];

ll modpow(ll a, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }

        n >>= 1;
        a = (a * a) % MOD;
    }

    return ans;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    invfac[MAXN - 1] = modpow(fac[MAXN - 1], MOD - 2);

    for (int i = MAXN - 2; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

ll comb(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

ll inv(ll x) {
    return modpow(x, MOD - 2);
}

// s: size
// comb(n - 1 - s, k - s + 1) / comb(n - 1, k)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int target = -1;
    int val = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > val) {
            target = i;
            val = a[i];
        }
    }

    vector<int> sz(n + 1), mx(n + 1);

    auto csize = [&](auto &&self, int u, int p) -> void {
        sz[u] = 1;
        mx[u] = a[u];
        for (int v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            mx[u] = max(mx[u], mx[v]);
            sz[u] += sz[v];
        }
    };

    csize(csize, target, 0);

    ll ans = 0;
    ll invD = inv(comb(n - 1, k));
    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (int v : G[u]) {
            if (v == p) continue;

            ll prob;
            int s;

            s = sz[v];
            prob = comb(n - 1 - s, k - s + 1) * invD % MOD;
            ans += mx[v] * prob % MOD;

            s = n - sz[v];
            prob = comb(n - 1 - s, k - s + 1) * invD % MOD;
            ans += val * prob % MOD;

            self(self, v, u);
        }
    };

    dfs(dfs, target, 0);
    ans %= MOD;

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}