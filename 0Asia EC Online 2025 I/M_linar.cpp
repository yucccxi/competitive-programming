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

#define MAXN 5005

const ll LINF = 1e18;

int n, m;
vector<edge> G[MAXN];
vector<edge> T[MAXN];

ll dist[MAXN], dist_cp[MAXN];

void dfs_up(int u, int p) {
    for (edge &e : G[u]) {
        int v = e.other(u);
        int w = e.weight;
        if (v == p || w == 0) continue;
        dfs_up(v, u);
        dist[u] = min(dist[u], dist[v] + w);
    }
}

void dfs_down(int u, int p) {
    for (edge &e : G[u]) {
        int v = e.other(u);
        int w = e.weight;
        if (v == p) continue;
        dist[v] = min(dist[v], dist[u] + w);
        dfs_down(v, u);
    }
}

void solve() {
    cin >> n >> m;

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
        T[u].push_back(e);
        T[v].push_back(e);
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = LINF;
    }

    dist[1] = 0;

    for (int k = 0; k <= n; k++) {
        dfs_up(1, 0);
        dfs_down(1, 0);

        ll ans = 0;
        for (int u = 1; u <= n; u++) {
            ans += dist[u];
            dist_cp[u] = dist[u];
        }

        cout << ans << endl;

        for (int u = 1; u <= n; u++) {
            for (edge e : T[u]) {
                int v = e.other(u);
                dist[v] = min(dist[v], dist_cp[u]);
            }
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