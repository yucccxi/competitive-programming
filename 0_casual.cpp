#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

map<int, ll> build_next(const map<int, ll> &mp) {
    map<int, ll> nxt;
    ll tot = 0;
    for (auto &[k, f] : mp) {
        tot += f;
    }

    int p0 = (tot + 1) / 2;
    int p1 = tot / 2;

    ll prev = 0;
    for (auto &[k, f] : mp) {
        ll l = prev + 1;
        ll r = l + f - 1;
        ll len = r - l + 1;

        ll cnt = len;
        if (p0 < l)      cnt += (2 * tot - l - r) * len / 2;
        else if (p0 > r) cnt += (l + r - 2) * len / 2;
        else {
            cnt += (l + p0 - 2) * (p0 - l + 1) / 2;
            cnt += (tot - (p0 + 1) + tot - r) * (r - p0) / 2;
        }

        if (p1 < l)      cnt += (2 * tot - l - r) * len / 2;
        else if (p1 > r) cnt += (l + r) * len / 2;
        else {
            cnt += (l + p1) * (p1 - l + 1) / 2;
            cnt += (tot - (p1 + 1) + (tot - r)) * (r - p1) / 2;
        }

        nxt[k] = cnt;

        prev += f;
    }

    return nxt;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, ll> mp;
    for (int i = 1; i <= n; i++) {
        mp[a[i]]++;
    }

    mp = build_next(mp);
    mp = build_next(mp);

    ll cnt = 0;
    for (auto &[k, f] : mp) {
        cnt += f;
    }

    ll mid = (cnt + 1) / 2;

    ll prev = 0;
    ll ans = -1;
    for (auto &[k, f] : mp) {
        if (prev + f >= mid) {
            ans = k;
            break;
        }

        prev += f;
    }

    assert(ans != -1);

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