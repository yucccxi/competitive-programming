#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 2e5 + 5;
const int MAXV = 1e6 + 5;
const int MOD  = 1e9 + 7;

int n, V;
int a[MAXN], freq[MAXV], cnt[MAXV], F[MAXV], G[MAXV];

ll ans;

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

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        V = max(V, a[i]);
        ++freq[a[i]];
    }

    for (int d = 1; d <= V; d++) {
        for (int v = d; v <= V; v += d) {
            cnt[d] += freq[v];
        }
    }

    for (int i = 1; i <= V; i++) {
        int x = cnt[i];
        if (x > 0) {
            F[i] = x * modpow(2, x - 1) % MOD;
        }
    }

    for (int v = MAXV - 1; v >= 1; v--) {
        G[v] = F[v];
        for (int d = 2 * v; d <= V; d += v) {
            G[v] -= G[d];
            if (G[v] < 0) G[v] += MOD;
        }
    }

    for (int i = 2; i <= V; i++) {
        ans += (ll)i * G[i] % MOD;
    }
    ans %= MOD;

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