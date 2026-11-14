#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e3 + 5;

int n, m;
int a[MAXN];

bool ans[MAXN][MAXN];

void solveeven() {
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (cnt < a[i] && (i & 1) == (j & 1)) {
                cout << 1;
                cnt++;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
}

void solveodd() {
    vector<int> all;
    for (int i = 1; i <= n; i++) {
        if (a[i] == (m + 1) / 2) {
            all.push_back(i);
        }
    }

    if (all.size() == 0) {
        solveeven();
        return;
    }

    for (int i = 1; i < all.size(); i++) {
        int l = all[i - 1] + 1, r = all[i] - 1;
        
    }

    for (int i : all) {
        for (int j = 1; j <= m; j += 2) {
            ans[i][j] = 1;
        }
    }

    for (int i = all[0] - 1; i >= 1; i--) {
        int ind = (all[0] - i) & 1;
        int cnt = 0;

        for (int j = 1 + ind; j <= m; j += 2) {
            if (cnt < a[i]) {
                ans[i][j] = 1;
                cnt++;
            }
        }
    }

    for (int i = all.back() + 1; i <= n; i++) {
        int ind = (i - all.back()) & 1;
        int cnt = 0;
        for (int j = 1 + ind; j <= m; j += 2) {
            if (cnt < a[i]) {
                ans[i][j] = 1;
                cnt++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] > (m + 1) / 2) {
            cout << -1 << endl;
            return;
        }

        if (i > 1 && (m & 1) && a[i] == (m + 1) / 2 && a[i - 1] == (m + 1) / 2) {
            cout << -1 << endl;
            return;
        }
    }

    if (m & 1) solveodd();
    else       solveeven();
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