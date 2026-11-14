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

const int MAXN = 1e5 + 5;
const int INF  = 1e9;

int n, m, V, T;

struct accumulator {

    int dropped;
    int used;

    accumulator(int _dropped = INF, int _used = INF) : dropped(_dropped), used(_used) {}

    accumulator add(int val) {
        accumulator ret = accumulator(dropped, used);
        if (used + val <= V) ret.used += val;
        else {
            ret.dropped++;
            ret.used = val;
        }

        return ret;
    }

    bool operator<(const accumulator &o) const {
        if (dropped != o.dropped) {
            return dropped < o.dropped;
        }
        return used < o.used;
    }

    bool operator>(const accumulator &o) const {
        if (dropped != o.dropped) {
            return dropped > o.dropped;
        }
        return used > o.used;
    }

    bool operator==(const accumulator &o) const {
        return dropped == o.dropped && used == o.used;
    }

    bool operator!=(const accumulator &o) const {
        return dropped != o.dropped || used != o.used;
    }
};

using meta = pair<accumulator, int>;

vector<edge> G[MAXN];
accumulator dist[MAXN];

void solve() {
    cin >> n >> m >> V >> T;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge e = edge(u, v, w);
        G[u].push_back(e);
        G[v].push_back(e);
    }

    priority_queue<meta, vector<meta>, greater<meta>> pq;
    dist[T] = accumulator(0, 0);
    pq.push({dist[T], T});

    while (pq.size() > 0) {
        meta tp = pq.top();
        pq.pop();

        accumulator d = tp.first;
        int u = tp.second;

        if (dist[u] != d) continue;

        for (edge e : G[u]) {
            int v = e.other(u);
            accumulator upd = dist[u].add(e.weight);
            if (upd < dist[v]) {
                dist[v] = upd;
                pq.push({upd, v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == T) {
            cout << 1 << " ";
            continue;
        }

        if (dist[i].dropped == INF) {
            cout << -1 << " ";
            continue;
        }

        cout << dist[i].dropped + (dist[i].used > 0) << " ";
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