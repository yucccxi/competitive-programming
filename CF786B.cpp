#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Meta = pair<ll, int>;

#define endl '\n'

const int MAXN = 1e5 + 5;

int n, q, s;

map<pair<int, int>, int> forw, rev;
int cur;

vector<pair<int, int>> G[MAXN * 3];

priority_queue<Meta, vector<Meta>, greater<Meta>> pq;
ll dist[MAXN * 3];

int buildForw(int l, int r) {

    if (l == r) return l;

    int u = ++cur;
    forw[{l, r}] = u;

    int mid = (l + r) >> 1;

    int vl = buildForw(l, mid);
    int vr = buildForw(mid + 1, r);
    G[u].push_back({0, vl});
    G[u].push_back({0, vr});

    return u;
}

int buildRev(int l, int r) {

    if (l == r) return l;

    int u = ++cur;
    rev[{l, r}] = u;

    int mid = (l + r) >> 1;

    int vl = buildRev(l, mid);
    int vr = buildRev(mid + 1, r);
    G[vl].push_back({0, u})``;
    G[vr].push_back({0, u});

    return u;
}

void solve() {
    cin >> n >> q >> s;
    cur = n;

    buildForw(1, n);
    buildRev(1, n);

    for (int i = 1; i <= n; i++) {
        rev[{i, i}] = i;
        forw[{i, i}] = i;
    }

    for (int i = 1; i <= q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int u, v, w;
            cin >> u >> v >> w;
            G[u].push_back({w, v});
        } else if (t == 2) {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            
            auto addEdge = [&](auto &&self, int _l, int _r) -> void {
                if (l <= _l && _r <= r) {
                    G[v].push_back({w, forw[{_l, _r}]});
                    return;
                }

                int mid = (_l + _r) >> 1;
                if (l <= mid) self(self, _l, mid);
                if (mid < r)  self(self, mid + 1, _r);
            };

            addEdge(addEdge, 1, n);
        } else if (t == 3) {
            int v, l, r, w;
            cin >> v >> l >> r >> w;

            auto addEdge = [&](auto &&self, int _l, int _r) -> void {
                if (l <= _l && _r <= r) {
                    G[rev[{_l, _r}]].push_back({w, v});
                    return;
                }

                int mid = (_l + _r) >> 1;
                if (l <= mid) self(self, _l, mid);
                if (mid < r)  self(self, mid + 1, _r);
            };

            addEdge(addEdge, 1, n);
        } else assert(false);
    }

    pq.push({0, s});
    dist[s] = 0;

    while (pq.size() > 0) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &[w, v] : G[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    ll magic;
    memset(&magic, 0x3f, sizeof(magic));

    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == magic ? -1 : dist[i]) << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dist, 0x3f, sizeof(dist));

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}