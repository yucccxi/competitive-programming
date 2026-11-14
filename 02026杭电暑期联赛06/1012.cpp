#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using int128 = __int128_t;

#define endl '\n'

int pred(int128 x) {
    if (x == 0) return 0;
    return x < 0 ? -1 : +1;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> T(n + 1);
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        T[p].push_back(i);
        T[i].push_back(p);
    }

    vector<int> delay(n + 1);

    auto dfs = [&](auto &&self, int u, int p) -> void {
        if (p != 0) {
            if (p == 1 || u < p) delay[u] = delay[p];
            else delay[u] = delay[p] + 1;
        }

        for (int v : T[u]) {
            if (v == p) continue;
            self(self, v, u);
        }
    };

    dfs(dfs, 1, 0);

    int128 tot = 0;
    for (int i = 2; i <= n; i++) {
        tot += a[i];
    }

    int128 current = 0;
    for (int i = 2; i <= n; i++) {
        current += (int128)(n - delay[i]) * a[i];
    }

    if (current == 0 && tot == 0) {
        cout << 0 << endl;
    } else {
        if (tot == 0) {
            cout << pred(current) << endl;
        } else {
            cout << pred(tot) << endl;
        }
    }
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