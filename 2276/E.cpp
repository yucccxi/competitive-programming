#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = '.' + s;
    vector<vector<int>> nxt(n + 2, vector<int>(10, n + 1));
    vector<int> pos(10);
    for (int i = n; i >= 1; i--) {
        pos[s[i] - '0'] = i;
        for (int j = 0; j < 10; j++) {
            nxt[i][j] = pos[j];
        }
    }

    vector<pair<int, int>> vec2025, vec2026;
    for (int i = 1; i <= n; i++) {
        if (s[i] != '2') continue;
        
        {
            int j = i;
            j = nxt[j][2];
            j = nxt[j][0];
            j = nxt[j][2];
            j = nxt[j][5];

            if (j != n + 1) {
                if (vec2025.size() == 0 || vec2025.back().second < j) {
                    vec2025.push_back({i, j});
                } else {
                    vec2025.back().second = j;
                }
            }
        }

        {
            int j = i;
            j = nxt[j][2];
            j = nxt[j][0];
            j = nxt[j][2];
            j = nxt[j][6];

            if (j != n + 1) {
                if (vec2026.size() == 0 || vec2026.back().second < j) {
                    vec2026.push_back({i, j});
                } else {
                    vec2026.back().second = j;
                }
            }
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