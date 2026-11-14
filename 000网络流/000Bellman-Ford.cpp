#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = (1u << 31) - 1;

const int MAXV = 1e4 + 5;
const int MAXE = 5e5 + 5;

int dist[MAXV];
tuple<int, int, int> edges[MAXE];

int n, m, s;

void solve() {
    cin >> n >> m >> s;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            auto &[u, v, w] = edges[j];
            if (dist[u] == INF) continue;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
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