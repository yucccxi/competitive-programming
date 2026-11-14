#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 0x3F3F3F3F;

const int MAXN = 2e5 + 5;
const int MAXM = 4e5 + 5;
const int MAXV = 1e6 + 5;

int n, m;
int p[MAXN], c[MAXN];
int tp[MAXM], tc[MAXM], d[MAXM];

int prefp[MAXV], prefc[MAXV], suffc[MAXV], suffp[MAXV];

int calcp(int i, int val) {
    if (val == INF) return INF;
    if (val < tp[i]) return 0;
    else if (val <= tp[i] + d[i]) return val;
    else return tp[i] + d[i];
}

int calcc(int i, int val) {
    if (val == INF) return INF;
    if (val < tc[i]) return 0;
    else if (val <= tc[i] + d[i]) return val;
    else return tc[i] + d[i];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> tp[i];
    for (int i = 1; i <= m; i++) cin >> tc[i];
    for (int i = 1; i <= m; i++) cin >>  d[i];

    memset(prefp, 0x3F, sizeof(prefp));
    memset(prefc, 0x3F, sizeof(prefc));
    memset(suffp, 0x3F, sizeof(suffp));
    memset(suffc, 0x3F, sizeof(suffc));

    for (int i = 1; i <= n; i++) {
        prefp[p[i]] = min(prefp[p[i]], c[i]);
        suffp[p[i]] = min(suffp[p[i]], c[i]);
        prefc[c[i]] = min(prefc[c[i]], p[i]);
        suffc[c[i]] = min(suffc[c[i]], p[i]);
    }

    for (int i = 1; i < MAXV; i++) {
        prefp[i] = min(prefp[i], prefp[i - 1]);
        prefc[i] = min(prefc[i], prefc[i - 1]);
    }

    for (int i = MAXV - 2; i >= 0; i--) {
        suffp[i] = min(suffp[i], suffp[i + 1]);
        suffc[i] = min(suffc[i], suffc[i + 1]);
    }

    int mn = INF;

    for (int i = 1; i <= n; i++) {
        mn = min(mn, p[i] + c[i]);
    }

    for (int i = 1; i <= m; i++) {
        int ans = mn;
        if (tp[i] - 1 >= 0) ans = min(ans, calcc(i, prefp[tp[i] - 1]));
        if (tc[i] - 1 >= 0) ans = min(ans, calcp(i, prefc[tc[i] - 1]));

        if (tp[i] + d[i] < MAXV) ans = min(ans, tp[i] + d[i] + calcc(i, suffp[tp[i] + d[i]]));
        if (tc[i] + d[i] < MAXV) ans = min(ans, tc[i] + d[i] + calcp(i, suffc[tc[i] + d[i]]));
        
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