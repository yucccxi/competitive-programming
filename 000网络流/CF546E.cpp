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

const int MAXN = 105;
const int MAXM = 205;

const ll MAX = 1e12;

int n, m;
int a[MAXN], b[MAXN], ans[MAXN][MAXN];

ll sma, smb;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        sma += a[i];
        smb += b[i];
    }

    if (sma != smb) {
        cout << "NO" << endl;
        return;
    }

    Dinic mf(2 * n + 2, 1, 2 * n + 2);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        mf.addEdge(u + 1, v + n + 1, MAX);
        mf.addEdge(v + 1, u + n + 1, MAX);
    }

    for (int i = 1; i <= n; i++) {
        mf.addEdge(i + 1, i + n + 1, MAX);
    }

    for (int i = 1; i <= n; i++) {
        mf.addEdge(1, i + 1, a[i]);
        mf.addEdge(i + 1 + n, 2 * n + 2, b[i]);
    }

    mf.compute();
    ll flow = mf.maxFlow();

    if (flow < sma) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        for (int id : mf.G[i + 1]) {
            if (id & 1) continue;
            
            Dinic::Edge &e = mf.edges[id];
            int j = e.to - n - 1;

            ll val = e.cap - e.res;
            ans[i][j] = val;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
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