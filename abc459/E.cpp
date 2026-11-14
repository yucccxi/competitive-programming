#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD  = 998244353;
const int MAXN = 1e6 + 5;

ll fac[MAXN], invfac[MAXN];

ll modpow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    invfac[MAXN - 1] = modpow(fac[MAXN - 1], MOD - 2);

    for (int i = MAXN - 1; i > 0; i--) {
        invfac[i - 1] = invfac[i] * i % MOD;
    }
}

ll comb_brute(ll n, int k) {
    if (k < 0 || k > n) return 0;

    ll f = 1;

    for (ll i = n; i >= n - k + 1; i--) {
        f = f * (i % MOD) % MOD;
    }

    f = f * invfac[k] % MOD;

    return f;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> T(n + 1);

    for (int u = 2; u <= n; u++) {
        int p;
        cin >> p;

        T[p].push_back(u);
        T[u].push_back(p);
    }

    vector<ll> c(n + 1);
    vector<int> d(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    vector<int> parent(n + 1, 0);

    vector<int> order;
    order.reserve(n);

    stack<int> st;
    st.push(1);
    parent[1] = -1;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        order.push_back(u);

        for (int v : T[u]) {
            if (v == parent[u]) continue;

            parent[v] = u;
            st.push(v);
        }
    }

    ll ans = 1;
    vector<ll> remain(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];

        ll cnt = c[u];

        for (int v : T[u]) {
            if (v == parent[u]) continue;
            cnt += remain[v];
        }

        ans = ans * comb_brute(cnt, d[u]) % MOD;

        remain[u] = cnt - d[u];
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}