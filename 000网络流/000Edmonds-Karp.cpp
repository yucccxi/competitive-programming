#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 205;
const ll  LINF = 1e18;

struct Edge {
    int from, to;
    ll cap, res;
};

int n, m, s, t;
vector<Edge> edges;
vector<int> G[MAXN];

int edgeTo[MAXN];
int marked[MAXN], tsp;

void addEdge(int u, int v, int cap) {
    G[u].push_back(edges.size());
    edges.push_back({u, v, cap, cap});
    G[v].push_back(edges.size());
    edges.push_back({v, u, cap, 0});
}

bool bfs() {
    ++tsp;
    queue<int> q;
    q.push(s);
    marked[s] = tsp;

    while (q.size() > 0) {
        int u = q.front();
        q.pop();

        for (int v : G[u]) {
            Edge &e = edges[v];
            if (marked[e.to] == tsp || e.res == 0) continue;

            q.push(e.to);

            edgeTo[e.to] = v;
            marked[e.to] = tsp;

            if (e.to == t) return true;
        }
    }

    return false;
}

void solve() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        addEdge(u, v, cap);
    }

    while (bfs()) {
        int u = t;

        ll minn = LINF;
        while (u != s) {
            Edge &e = edges[edgeTo[u]];
            minn = min(minn, e.res);
            u = e.from;
        }

        u = t;
        while (u != s) {
            Edge &e   = edges[edgeTo[u]];
            Edge &rev = edges[edgeTo[u] ^ 1];
            e.res -= minn;
            rev.res += minn;
            u = e.from;
        }
    }

    ll ans = 0;
    for (int u : G[s]) {
        if (u & 1) continue;
        ans += edges[u].cap - edges[u].res;
    }

    cout << ans << endl;
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