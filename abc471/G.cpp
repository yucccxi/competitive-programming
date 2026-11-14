#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using ull = unsigned long long;
using uint = unsigned int;

#define endl '\n'

const int MOD = 998244353;
const int G   = 3;          // 原根
const int IG  = 332748118;  // 原根的逆元

ll modpow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }

        b >>= 1;
        a = (a * a) % MOD;
    }

    return ans;
}

// 迭代版本
void nttit(vector<int> &a, int type) {
    int n = a.size();

    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
    }

    for (int i = 0; i < n; i++) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }

    for (int l = 1; l < n; l <<= 1) {
        ll w0 = modpow(type == 1 ? G : IG, (MOD - 1) / (l * 2));
        for (int i = 0; i < n; i += (l << 1)) {
            ll w = 1;
            for (int j = i; j < i + l; j++) {
                ll u = a[j] % MOD;
                ll v = w * a[j + l] % MOD;
                a[j]     = (u + v) % MOD;
                a[j + l] = (u - v + MOD) % MOD;
                w = (w * w0) % MOD;
            }
        }
    }
}

void solve() {
    int n, k, m;
    ull seed;
    cin >> n >> k >> seed >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    int nk = 1;
    while (nk <= k) nk <<= 1;

    vector<bool> v(nk);
    for (int i = 0; i < k; i++) {
        bool x; cin >> x;
        v[i] = x;
        v[i + k] = x;
    }

    ull state = seed;
    for (int i = m + 1; i <= n; i++) {
        uint x = ((state >> 18) ^ state) >> 27;
        uint r = state >> 59;
        uint y = (x >> r) + (x << (32 - r));
        a[i] = y % k;
        state = state * 6364136223846793005ULL + 2026081520260815ULL;
    }

    vector<vector<int>> cnt(k, vector<int>(nk));
    for (int i = 2; i <= n; i++) {
        cnt[a[i - 1]][a[i]]++;
    }

    vector<vector<int>> all(k);

    for (int i = 0; i < k; i++) {
        if () {

        }
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