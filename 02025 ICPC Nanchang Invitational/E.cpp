#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 3e5 + 5;

struct Q { int l, r, i; };

int n, m, k, sq, curl = 0, curr = -1;
string s;

vector<vector<int>> pref, t;

vector<int> h;

int f[MAXN];
ll ans[MAXN], curans;

Q q[MAXN];

void solve() {
    cin >> n >> k >> m;
    cin >> s;
    s = '.' + s;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }

    int sq = sqrt(n) + 1;

    sort(q + 1, q + 1 + m, [&](const Q &q1, const Q &q2) -> bool {
        int b1 = (q1.l - 1) / sq;
        int b2 = (q2.l - 1) / sq;
        if (b1 != b2) return b1 < b2;
        return q1.r < q2.r;
    });

    pref.resize(n + 1, vector<int>(26));
    h.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            pref[i][j] = pref[i - 1][j];
        }
        pref[i][s[i] - 'a']++;

        if (pref[i][s[i] - 'a'] == k) {
            pref[i][s[i] - 'a'] -= k;
        }
    }

    t = pref;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (int i = 0; i <= n; i++) {
        h[i] = lower_bound(t.begin(), t.end(), pref[i]) - t.begin();
    }

    auto swift = [&](int l, int r) -> void {
        while (curl > l) {
            --curl;
            int c = h[curl];
            curans += f[c];
            ++f[c];
        }

        while (curr < r) {
            ++curr;
            int c = h[curr];
            curans += f[c];
            ++f[c];
        }

        while (curl < l) {
            int c = h[curl];
            curans -= f[c] - 1;
            --f[c];
            ++curl;
        }

        while (curr > r) {
            int c = h[curr];
            curans -= f[c] - 1;
            --f[c];
            --curr;
        }
    };

    for (int i = 1; i <= m; i++) {
        auto &[l, r, j] = q[i];
        swift(l - 1, r);
        ans[j] = curans;
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
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