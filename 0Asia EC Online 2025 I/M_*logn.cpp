#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct edge {
    int p, q, weight;
    edge(int u, int v, int w) : p(u), q(v), weight(w) {}
    edge() : p(0), q(0), weight(0) {}
    int either() { return p; }
    int other(int v) { return v == p ? q : p; }
    bool operator<(const edge &other) const { return weight < other.weight; }
    bool operator>(const edge &other) const { return weight > other.weight; }
};

// distance, vertice, layer
using meta = tuple<ll, int, int>;

const int MAXN = 5e3 + 5;
const ll  LINF = 1e18;

int n, m;
vector<edge> G[MAXN];

ll dist[MAXN][MAXN];
ll mini[MAXN];

void dijkstra() {
    priority_queue<meta, vector<meta>, greater<meta>> pq;
    dist[1][0] = 0;
    pq.push({dist[1][0], 1, 0});

    while (pq.size() > 0) {
        auto [d, u, l] = pq.top();
        pq.pop();

        if (d > dist[u][l]) continue;

        for (edge e : G[u]) {
            int v = e.other(u);
            int w = e.weight;

            if (w > 0) {
                if (d + w < dist[v][l]) {
                    dist[v][l] = d + w;
                    pq.push({dist[v][l], v, l});
                }

                // if (u == 1 && l == 0) {
                //     cout << v << " " << w << endl;
                //     cout << "===>" << dist[v][l] << endl;
                // }

            } else if (l < n) {
                if (d < dist[v][l + 1]) {
                    dist[v][l + 1] = d;
                    pq.push({dist[v][l + 1], v, l + 1});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        mini[i] = LINF;
        for (int j = 0; j <= n; j++) {
            dist[i][j] = LINF;
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge e = edge(u, v, w);
        G[u].push_back(e);
        G[v].push_back(e);
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge e = edge(u, v, 0);
        G[u].push_back(e);
        G[v].push_back(e);
    }

    dijkstra();

    for (int k = 0; k <= n; k++) {
        ll ans = 0;
        for (int u = 1; u <= n; u++) {
            mini[u] = min(mini[u], dist[u][k]);
            // cout << dist[u][k] << " ";
            ans += mini[u];
        }

        // cout << endl;

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