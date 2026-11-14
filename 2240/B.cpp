#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

template<int MOD>
struct modint {
    int val;
    
    modint() : val(0) {}
    modint(long long v) {
        val = v % MOD;
        if (val < 0) val += MOD;
    }
    
    modint& operator++() { val = (val + 1 == MOD ? 0 : val + 1); return *this; }
    modint& operator--() { val = (val == 0 ? MOD - 1 : val - 1); return *this; }
    modint operator++(int) { modint res = *this; ++*this; return res; }
    modint operator--(int) { modint res = *this; --*this; return res; }

    modint operator-() const { modint res = *this; res.val = (res.val == 0 ? 0 : MOD - res.val); return res;};
    modint operator+() const { return *this; };
    
    modint& operator+=(const modint& o) { val += o.val; if (val >= MOD) val -= MOD; return *this; }
    modint& operator-=(const modint& o) { val -= o.val; if (val < 0) val += MOD; return *this; }
    modint& operator*=(const modint& o) { val = 1LL * val * o.val % MOD; return *this; }
    modint& operator/=(const modint& o) { return *this *= o.inv(); }
    
    friend modint operator+(modint a, const modint& b) { return a += b; }
    friend modint operator-(modint a, const modint& b) { return a -= b; }
    friend modint operator*(modint a, const modint& b) { return a *= b; }
    friend modint operator/(modint a, const modint& b) { return a /= b; }

    friend bool operator==(const modint& a, const modint& b) { return a.val == b.val; }
    friend bool operator!=(const modint& a, const modint& b) { return a.val != b.val; }
    
    modint pow(long long p) const {
        modint res = 1, a = *this;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }

    modint inv() const {
        return pow(MOD - 2);
    }
    
    friend std::ostream& operator<<(std::ostream& os, const modint& m) { return os << m.val; }
    friend std::istream& operator>>(std::istream& is, modint& m) { long long v; is >> v; m = modint(v); return is; }
};

using mint = modint<998244353>;

mint modpow(mint a, ll n) {
    mint ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans *= a;
        }

        a *= a;
        n >>= 1;
    }

    return ans;
}

void solve() {
    ll n, m, r, c;
    cin >> n >> m >> r >> c;

    cout << modpow(2, n * m - (n - r + 1) * (m - c + 1)) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}