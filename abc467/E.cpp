#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll LINF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        cin >> b[i];
    }

    vector<ll> need(n);
    for (int i = n - 1; i >= 1; i--) {
        ll cur = (b[i] - (a[i] + a[i + 1]) % m + m) % m;
        need[i] = cur;
    }

    vector<ll> suff(n + 1);
    for (int i = n - 1; i >= 1; i--) {
        suff[i] = need[i] - suff[i + 1] + m;
        suff[i] %= m;
    }

    map<int, ll> mp;

    for (int i = n; i >= 1; i--) {
        ll sign = ((i - n) & 1) ? -1 : +1;
        ll cnt  = sign == +1 ? m - suff[i] : suff[i] + 1;
        mp[cnt] += -sign * m;
    }

    ll ans = LINF;
    ll cur = 0;
    ll last = 0;
    for (int i = n - 1; i >= 1; i--) {
        ll k = (need[i] - last + m) % m;
        cur += k;
        last = k;
    }

    for (auto &[cnt, inc] : mp) {
        cur += inc;
        ans = min(ans, cur + cnt * (n & 1)); // 如果 n 是奇数的话，±t 会有一个正的不能抵消
    }

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