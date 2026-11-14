#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

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
    int n, m, q;
    cin >> n >> m >> q;
    set<int> visited;

    vector<int> all;
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        all.push_back(x);
    }

    sort(all.begin(), all.end());

    for (int i = all.size() - 1; i >= 0; i--) {
        int x = all[i];
        int last = n / x * x;
        while (last > x && visited.count(last)) {
            last -= x;
        }

        if (!visited.count(last)) {
            visited.insert(last);
        }
    }

    cout << modpow(m, n - visited.size()) << endl;
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