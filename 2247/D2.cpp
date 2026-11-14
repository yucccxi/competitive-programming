#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 0x3f3f3f3f;

void solve() {
    int n, q; cin >> n >> q;
    int lg = 32 - __builtin_clz(n);

    vector<vector<int>> mn(lg + 1);
    vector<vector<int>> mx(lg + 1);
    
    for (int p = 0; p <= lg; p++) {
        int len = 1 << (lg - p);
        mn[p].resize(len);
        mx[p].resize(len);
    }

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mn[0][i] = x;
        mx[0][i] = x;
    }

    for (int i = n; i < (1 << lg); i++) {
        mn[0][i] = INF;
    }

    for (int p = 1; p <= lg; p++) {
        for (int i = 0; i < (1 << (lg - p)); i++) {
            mn[p][i] = min(mn[p - 1][i << 1], mn[p - 1][i << 1 | 1]);
            mx[p][i] = max(mx[p - 1][i << 1], mx[p - 1][i << 1 | 1]);
        }
    }

    vector<int> bad(lg + 1);
    for (int p = 0; p <= lg; p++) {
        for (int i = 1; i < (1 << (lg - p)); i++) {
            if (mx[p][i - 1] > mn[p][i]) {
                bad[p]++;
            }
        }
    }

    for (int i = 0; i <= lg; i++) {
        if (bad[i] == 0) {
            cout << (i == 0 ? 0 : (1 << (i - 1))) << endl;
            break;
        }
    }

    while (q--) {
        int pos, v;
        cin >> pos >> v;

        for (int p = 0; p <= lg; p++) {
            int len = 1 << p;
            int cnt = 1 << (lg - p);
            int i = pos / len;

            if (i>= 1       && mx[p][i - 1] > mn[p][i]) bad[p]--;
            if (i + 1 < cnt && mx[p][i] > mn[p][i + 1]) bad[p]--;

            if (p >= 1) {
                mx[p][i] = max(mx[p - 1][i << 1], mx[p - 1][i << 1 | 1]);
                mn[p][i] = min(mn[p - 1][i << 1], mn[p - 1][i << 1 | 1]);
            } else {
                mn[0][pos] = v;
                mx[0][pos] = v;
            }

            if (i >= 1      && mx[p][i - 1] > mn[p][i]) bad[p]++;
            if (i + 1 < cnt && mx[p][i] > mn[p][i + 1]) bad[p]++;
        }

        for (int i = 0; i <= lg; i++) {
            if (bad[i] == 0) {
                cout << (i == 0 ? 0 : (1 << (i - 1))) << endl;
                break;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}