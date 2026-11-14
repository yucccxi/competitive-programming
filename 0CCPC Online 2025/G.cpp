#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e5 + 5;

int n, q;
int a[MAXN];
ll tot[MAXN];
pair<int, int> queries[MAXN];
vector<int> idx[MAXN];

map<int, map<int, ll>> ans;

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

    int sq = (int)sqrt(n) + 1;
    const int B = n < 1000 ? sq : 1000;

    for (int i = 1; i <= n; i++) {
        idx[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (idx[a[i]].size() < B || ans.find(a[i]) != ans.end()) continue;

        vector<int> modified;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (tot[a[j]] == 0) {
                modified.push_back(a[j]);
            }

            tot[a[j]] += cnt;
            if (a[j] == a[i]) cnt++;
        }

        for (int j = 1; j <= n; j++) {
            ans[a[i]][j] = tot[j];
        }

        for (int v : modified) {
            tot[v] = 0;
        }
    }

    for (int i = 1; i <= q; i++) {
        auto &[u, v] = queries[i];

        if (u == -1 || v == -1) {
            cout << 0 << endl;
            continue;
        }

        if (idx[u].size() < B) {
            ll current = 0;
            for (int j : idx[u]) {
                current += idx[v].end() - upper_bound(idx[v].begin(), idx[v].end(), j);
            }

            cout << current << endl;
        } else {
            cout << ans[u][v] << endl;
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