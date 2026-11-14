#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int INF  = 1e9 + 7;

constexpr int MAXN = 1e7 + 5;
bitset<MAXN> composite;
int primes[MAXN], mu[MAXN], cnt;

void euler() {
    mu[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!composite[i]) {
            primes[cnt++] = i;
            mu[i] = -1;
        }

        for (int j = 0; j < cnt; j++) {
            int x = primes[j];
            ll nx = (ll)i * x;
            if (nx >= MAXN) break;
            composite[nx] = true;
            if (i % x == 0) {
                mu[nx] = 0;
                break;
            } else {
                mu[nx] = -mu[i];
            }
        }
    }
}

void solve() {
    int l, r, n;
    cin >> l >> r >> n;

    int p = lower_bound(primes, primes + cnt, n) - primes;
    p = (p == 0 ? 1 : primes[p - 1]);

    int R = min(r, p);

    ll ans = 0;

    if (R >= l) {
        ans += 2 * (R - l + 1);

        vector<int> factors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i * i != n) {
                    factors.push_back(n / i);
                }
            }
        }

        ll C = 0;
        for (int d : factors) {
            C += mu[d] * (R / d - (l - 1) / d);
        }

        ans -= C;
    }

    R = max(R, l - 1);

    if (R < r) {
        vector<int> dp(n - R, INF);
        dp[n - R - 1] = 0;

        for (int i = n; i >= R + 1; i--) {
            for (int j = R + 1; j < i; j++) {
                int u = i - R - 1, v = j - R - 1;
                dp[v] = min(dp[v], dp[u] + __gcd(i, j));
            }
        }

        for (int i = R + 1; i <= r; i++) {
            ans += dp[i - R - 1];
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    euler();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}