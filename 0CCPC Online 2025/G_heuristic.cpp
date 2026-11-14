#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e5 + 5;

int n, q;
int a[MAXN];
pair<int, int> queries[MAXN];
vector<int> idx[MAXN];

map<int, map<int, bool>> calculated;
map<int, map<int, ll>> memo;

void compress() {
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = a[i];
    }

    sort(v.begin() + 1, v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }

    for (int i = 1; i <= q; i++) {
        int rk;

        rk = lower_bound(v.begin(), v.end(), queries[i].first) - v.begin();
        queries[i].first = (rk == v.size() || v[rk] != queries[i].first ? -1 : rk);
        rk = lower_bound(v.begin(), v.end(), queries[i].second) - v.begin();
        queries[i].second = (rk == v.size() || v[rk] != queries[i].second ? -1 : rk);
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    compress();

    for (int i = 1; i <= n; i++) {
        idx[a[i]].push_back(i);;
    }

    for (int i = 1; i <= q; i++) {
        auto &[u, v] = queries[i];
        if (u == -1 || v == -1) {
            cout << 0 << endl;
            continue;
        }

        if (calculated[u][v]) {
            cout << memo[u][v] << endl;
            continue;
        }

        ll ans = 0;
        if (idx[u].size() <= idx[v].size()) {
            for (int j : idx[u]) {
                ans += idx[v].end() - upper_bound(idx[v].begin(), idx[v].end(), j);
            }
        } else {
            for (int j : idx[v]) {
                ans += lower_bound(idx[u].begin(), idx[u].end(), j) - idx[u].begin();
            }
        }

        calculated[u][v] = true;
        memo[u][v] = ans;

        cout << ans << endl;
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