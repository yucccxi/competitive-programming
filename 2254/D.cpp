#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<ll> b(n + 1);

    bool ok = false;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == 0) ok = true;
    }

    if (!ok) {
        cout << -1 << endl;
        return;
    }

    map<ll, int> f;
    map<ll, vector<int>> idx;
    for (int i = 1; i <= n; i++) {
        f[b[i]]++;
        idx[b[i]].push_back(i);
    }

    vector<pair<ll, int>> all;
    for (auto &p : f) {
        all.push_back(p);
    }

    map<ll, ll> ans;

    ll tot = 0;
    ll lastans = 0;
    for (int i = 1; i < all.size(); i++) {
        if ((all[i].first - tot) % all[i - 1].second != 0) {
            cout << -1 << endl;
            return;
        }

        ll last = (all[i].first - tot) / all[i - 1].second;

        if (last <= lastans) {
            cout << -1 << endl;
            return;
        }

        ans[all[i - 1].first] = last;
        tot += last * all[i - 1].second;
        lastans = last;
    }

    ans[all.back().first] = lastans + 1;

    vector<ll> a(n + 1);
    for (auto [u, v] : ans) {
        for (int i : idx[u]) {
            a[i] = v;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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