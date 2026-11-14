#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e6 + 5  ;
const int MOD  = 998244353;

int n;
vector<int> all[MAXN];
int cnt[MAXN];

ll prob = 0;

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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        all[i].resize(k);
        for (int &x : all[i]) {
            cin >> x;
            cnt[x]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        int k = all[i].size();
        for (int j = 0; j < k; j++) {
            prob += inv(n) * inv(k) % MOD * cnt[all[i][j]] % MOD * inv(n) % MOD;
        }
    }

    prob %= MOD;

    cout << prob << endl;
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