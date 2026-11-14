#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct Edge {
    int u, v, k;
    
    bool operator<(const Edge &o) const {
        if (u != o.u) return u < o.u;
        if (v != o.v) return v < o.v;
        return k < o.k;
    }
};

const int MAXN = 3e5 + 5;

int n, m, k, q;
set<Edge> G[MAXN];
set<Edge> cut[MAXN];

bool marked[MAXN];
int tot;

void visit(int u) {
    if (marked[u]) return;
    marked[u] = true;
    ++tot;
    
    for (const Edge &e : G[u]) {
        if (marked[e.v]) continue;
        cut[e.k].insert(e);
    }
}

void solve() {
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= m; i++) {
        int u, v, _k;
        cin >> u >> v >> _k;
        Edge e = {u, v, _k};
        G[u].insert(e);
    }
    
    visit(1);
    
    while (q--) {
        int op;
        cin >> op;
        
        if (op == 1) {
            int u, v, _k;
            cin >> u >> v >> _k;
            if (marked[v]) continue;
            
            Edge e = {u, v, _k};
            
            if (marked[u]) {
                cut[_k].insert(e);
            } else {
                G[u].insert(e);
            }
        } else if (op == 2) {
            int u, v, _k;
            cin >> u >> v >> _k;
            if (marked[v]) continue;
            
            Edge e = {u, v, _k};
            
            if (marked[u]) {
                cut[_k].erase(e);
            } else {
                G[u].erase(e);
            }
        } else if (op == 3) {
            int _k; cin >> _k;
            
            set<Edge> st = cut[_k];
            cut[_k].clear();
            for (const Edge &e : st) {
                visit(e.v);
            }
            
            cout << tot << endl;
            
        } else assert(false);
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