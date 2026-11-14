#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1005;
const int MAXM = 2005;

const double DINF = 1e18;
const double EPS  = 1e-9;

struct edge {
    int p, q;
    double weight;
    edge(int u, int v, double w) : p(u), q(v), weight(w) {}
    edge() : p(0), q(0), weight(0) {}
    int from() const { return p; }
    int to() const { return q; }
    bool operator<(const edge &other) const { return weight < other.weight; }
    bool operator>(const edge &other) const { return weight > other.weight; }
};

int n, m;
vector<edge> G[MAXN];

bool bellman_ford(double mid) {
    vector<double> dist(n + 1, DINF);
    dist[0] = 0;

    double inc = -log(mid);

    for (int i = 1; i <= n + 1; i++) {
        bool updated = false;
        
        for (int u = 0; u <= n; u++) {
            if (dist[u] == DINF) continue;
            
            for (auto &e : G[u]) {
                int v = e.to();
                double w = e.weight + (u == 0 ? 0 : inc); 
                
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    updated = true;
                    if (i == n + 1) return true; 
                }
            }
        }
        if (!updated) break;
    }

    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edge e = edge(b, d, -log((double)c / a));
        G[b].push_back(e);
    }

    for (int i = 1; i <= n; i++) {
        edge e = edge(0, i, 0);
        G[0].push_back(e);
    }

    double l = 0, r = 1;
    while (r - l >= EPS) {
        double mid = (l + r) / 2;
        if (bellman_ford(mid)) r = mid;
        else l = mid;
    }

    cout << fixed << setprecision(9) << l << endl;
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