#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 2e5 + 5;

int n, m;
vector<int> T[MAXN];

int depth[MAXN];
map<int, vector<int>> all[MAXN];

void dfsd(int u, int p) {
    depth[u] = depth[p] + 1;
    for (int v : T[u]) {
        if (v == p) continue;
        dfsd(v, u);
    }
}

map<int, vector<int>> dfs(int u, int p) {
    map<int, vector<int>> cur;
    set<int> st;
    for (int v : T[u]) {
        if (v == p) continue;
        map<int, vector<int>> prev = dfs(v, u);
        if (prev.size() > cur.size()) {
            swap(prev, cur);
        }

        for (auto &[d, vec] : prev) {
            if (vec.size() + cur[d].size() >= 2) {
                st.insert(d);
            } else for (int x : vec) {
                cur[d].push_back(x);
            }
        }
    }

    for (auto &[d, vec] : all[u]) {
        if (vec.size() + cur[d].size() >= 2) {
            st.insert(d);
        } else for (int x : vec) {
            cur[d].push_back(x);
        }
    }

    for (int x : st) {
        cur.erase(x);
    }

    return cur;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfsd(1, 0);

    for (int i = 1; i <= m; i++) {
        int x, s;
        cin >> x >> s;
        int d = depth[x] + s;
        all[x][d].push_back(i);
    }

    map<int, vector<int>> alive = dfs(1, 0);
    vector<bool> ans(m + 1);
    for (auto &[d, vec] : alive) {
        for (int x : vec) {
            ans[x] = true;
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i];
    }
    cout << endl;
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