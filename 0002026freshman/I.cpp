#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (auto &s : g) cin >> s;

    vector<pair<int, int>> js;
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            if (g[i][k] == 'J') js.push_back({i, k});

    auto at = [&](int r, int c) -> int {   // 0 空, 1 J, 2 B, 3 越界
        if (r < 0 || r >= n || c < 0 || c >= n) return 3;
        if (g[r][c] == 'J') return 1;
        if (g[r][c] == 'B') return 2;
        return 0;
    };

    ll best = 0;
    for (size_t i = 0; i < js.size(); i++) {
        for (size_t k = i + 1; k < js.size(); k++) {
            int dx = js[k].first - js[i].first;
            int dy = js[k].second - js[i].second;
            int d2 = dx * dx + dy * dy;
            if (d2 % 2) continue;                    // 顶点不在格点上

            int sx = js[i].first + js[k].first;
            int sy = js[i].second + js[k].second;
            int r1 = (sx - dy) / 2, c1 = (sy + dx) / 2;
            int r2 = (sx + dy) / 2, c2 = (sy - dx) / 2;

            int cntJ = 2, cntEmpty = 0;
            bool ok = true;
            for (auto [r, c] : {pair{r1, c1}, pair{r2, c2}}) {
                int t = at(r, c);
                if (t == 3) { ok = false; break; }
                if (t == 1) cntJ++;
                else if (t == 0) cntEmpty++;
            }
            if (!ok) continue;
            if (cntJ == 4 || (cntJ == 3 && cntEmpty == 1)) {
                best = max(best, (ll)d2 / 2);
            }
        }
    }
    cout << best << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}