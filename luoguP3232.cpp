#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 505;
const double EPS = 1e-10;

int n, m;
vector<int> G[MAXN];
vector<pair<int, int>> edges;
vector<double> expectation;

double mat[MAXN][MAXN];

void gauss() {
    for (int i = 1; i <= n - 1; i++) {
        if (abs(mat[i][i]) < EPS) {
            int r;
            for (r = i + 1; r <= n - 1; r++) {
                if (abs(mat[r][i]) > EPS) break;
            }

            if (r == n) continue;

            for (int j = i; i <= n; j++) {
                swap(mat[i][j], mat[r][j]);
            }
        }

        for (int j = i + 1; j <= n - 1; j++) {
            if (abs(mat[j][i]) < EPS) continue;
            double ratio = mat[j][i] / mat[i][i];
            for (int k = i; k <= n; k++) {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
    }

    mat[n - 1][n] /= mat[n - 1][n - 1];
    mat[n - 1][n - 1] = 1;

    for (int i = n - 2; i >= 1; i--) {
        for (int j = n - 1; j > i; j--) {
            mat[i][n] -= mat[i][j] * mat[j][n];
            mat[i][j] = 0;
        }

        mat[i][n] /= mat[i][i];
        mat[i][i] = 1;
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});

        G[u].push_back(v);
        G[v].push_back(u);
    }

    mat[1][n] = 1;
    for (int u = 1; u <= n - 1; u++) {
        mat[u][u] = 1;
        for (int v : G[u]) {
            if (v == n) continue;
            mat[u][v] -= 1.0 / G[v].size();
        }
    }

    gauss();

    for (auto &[u, v] : edges) {
        double current = 0;
        current += mat[u][n] / G[u].size();
        current += mat[v][n] / G[v].size();
        expectation.push_back(current);
    }

    sort(expectation.rbegin(), expectation.rend());

    double ans = 0;
    for (int i = 0; i < expectation.size(); i++) {
        ans += expectation[i] * (i + 1);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(3);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}