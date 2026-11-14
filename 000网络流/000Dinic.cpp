#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll LINF = 9e18;

struct Dinic {
    struct Edge {
        int from, to;
        ll cap, res;
    };

    int n, s, t;
    vector<Edge> edges;
    vector<vector<int>> G;

    int curtag;
    vector<int> level, tag;

    Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        G.resize(n + 1);
        tag.resize(n + 1);
        level.resize(n + 1);

        curtag = 0;
    }

    void addEdge(int from, int to, ll cap) {
        G[from].push_back(edges.size());
        edges.push_back({from, to, cap, cap});
        G[to].push_back(edges.size());
        edges.push_back({to, from, cap, 0});
    }

    bool layering() {
        ++curtag;

        queue<int> q;
        q.push(s);
        tag[s] = curtag;
        level[s] = 0;

        while (q.size() > 0) {
            int u = q.front();
            q.pop();

            for (int id : G[u]) {
                Edge &e = edges[id];
                int v = e.to;
                if (e.res <= 0 || tag[v] == curtag) continue;
                
                level[v] = level[u] + 1;
                tag[v] = curtag;
                q.push(v);

                if (v == t) {
                    return true;
                }
            }
        }

        return false;
    }

    bool block() {
        if (!layering()) return false;

        vector<int> cur(n + 1, 0);

        auto dfs = [&](auto &&self, int u, ll limit) -> ll {
            if (u == t) return limit;

            int sz = G[u].size();
            for (int &i = cur[u]; i < sz; i++) {
                int id = G[u][i];
                Edge &e = edges[id];
                int v = e.to;

                if (e.res <= 0 || tag[v] != curtag || level[v] != level[u] + 1) {
                    continue;
                }

                ll pushed = self(self, v, min(limit, e.res));
                if (pushed == 0) continue;

                e.res -= pushed;
                edges[id ^ 1].res += pushed;

                return pushed;
            }

            return 0;
        };

        while (dfs(dfs, s, LINF) > 0);

        return true;
    }

    void compute() { while (block()); }

    ll maxFlow() {
        ll ret = 0;
        for (int id : G[s]) {
            if (id & 1 ^ 1) {
                ret += edges[id].cap - edges[id].res;
            }
        }

        return ret;
    }
};

int n, m, s, t;

void solve() {
    cin >> n >> m >> s >> t;

    Dinic mf(n, s, t);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mf.addEdge(u, v, w);
    }

    mf.compute();
    
    cout << mf.maxFlow() << endl;
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