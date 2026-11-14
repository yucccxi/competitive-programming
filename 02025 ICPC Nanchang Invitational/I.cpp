#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;
const int MAXN = 1e5 + 5;

int n, k;
ll fac[MAXN], invfac[MAXN];

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

ll comb(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    invfac[MAXN - 1] = inv(fac[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

void solve() {
    cin >> n >> k;
    string s; cin >> s;
    s = '.' + s + '1';

    vector<pair<int, int>> intervals;

    int cnt = 0;
    int l = 1, r = 1;
    while (true) {
        while (r <= n + 1 && cnt <= k) {
            if (s[r++] == '1') cnt++;
        }

        if (cnt <= k) break;

        intervals.push_back({l, r - 1});

        while (cnt > k) {
            if (s[l++] == '1') cnt--;
        }
    }

    if (intervals.size() == 0) {
        cout << 0 << endl;
        return;
    }

    ll ans = comb(intervals[0].second - intervals[0].first, k);

    for (int i = 1; i < intervals.size(); i++) {
        auto &[l, r] = intervals[i];
        ans += comb(r - l, k);
        ans -= comb(intervals[i - 1].second - l, k - 1);
        ans = ((ans % MOD) + MOD) % MOD;
    }

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

// g++ I_.cpp -o out && ./out < in.txt