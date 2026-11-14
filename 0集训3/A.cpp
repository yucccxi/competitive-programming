#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e7 + 5;

bool is_prime[MAXN];
int primes[MAXN / 10];
int cnt = 0;

void sieve() {
    memset(is_prime, true, sizeof(is_prime));

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < MAXN; i++) {

        if (is_prime[i]) {
            primes[cnt++] = i;
        }

        for (int j = 0; j < cnt && (ll)i * primes[j] < MAXN; j++) {

            is_prime[i * primes[j]] = false;

            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    int n; cin >> n;

    ll ans = 0;

    for (int i = 3; i <= n; i++) {
        if (is_prime[i]) {
            ans += 2 * i;
        } else {
            ans += i;
        }
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