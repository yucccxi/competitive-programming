#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e3 + 5;

mt19937 rng(random_device{}());

int n, m;
int a[MAXN];

bool ans[MAXN][MAXN];

bool solveeven() {
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (cnt < a[i] && (i & 1) == (j & 1)) {
                ans[i][j] = 1;
                cnt++;
            } else {
                ans[i][j] = 0;
            }
        }
    }

    return true;
}

bool solveodd() {
    vector<int> all;
    for (int i = 1; i <= n; i++) {
        if (a[i] == (m + 1) / 2) {
            all.push_back(i);
        }
    }

    if (all.size() == 0) {
        return solveeven();
    }

    for (int i = 1; i < all.size(); i++) {
        int l = all[i - 1] + 1;
        int r = all[i] - 1;

        bool ok = (r - l + 1) & 1;
        int pos = -1;
        if (!ok) {
            for (int j = l; j <= r; j++) {
                if ((j - l + 1) & 1) {
                    if (a[j] + a[j + 1] <= m / 2) {
                        pos = j;
                        ok = true;
                        break;
                    }
                } else if (j + 1 <= r && a[j] + a[j + 1] <= (m + 1) / 2) {
                    pos = j;
                    ok = true;
                    break;
                }
            }
        }

        if (!ok) {
            return false;
        }

        for (int j = l; j <= r; j++) {
            int ind = (j - l + 1) & 1 ^ (j >= pos + 1);
            int st = 1 + ind;
            if (j == pos + 1) {

                int cnt = 0;
                for (int k = m; k >= 1; k -= 2) {
                    if (cnt < a[j]) {
                        ans[j][k] = 1;
                        cnt++;
                    }
                }

                continue;
            }

            int cnt = 0;
            for (int k = st; k <= m; k += 2) {
                if (cnt < a[j]) {
                    ans[j][k] = 1;
                    cnt++;
                }
            }
        }
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

    return true;
}

bool solve() {
    // cin >> n >> m;
    // for (int i = 1; i <= n; i++) {
    //     cin >> a[i];
    // }

    for (int i = 1; i <= n; i++) {
        if (a[i] > (m + 1) / 2) {
            return false;
        }

        if (i > 1 && a[i] == (m + 1) / 2 && a[i - 1] == (m + 1) / 2) {
            return false;
        }
    }

    if (m & 1) return solveodd();
    else       return solveeven();
}

bool check() {
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (!ans[i][j]) continue;
            cnt++;
            if (i - 1 >= 1 && ans[i - 1][j]) return false;
            if (j - 1 >= 1 && ans[i][j - 1]) return false;
            if (i + 1 <= n && ans[i + 1][j]) return false;
            if (j + 1 <= m && ans[i][j + 1]) return false;
        }

        if (cnt != a[i]) return false;
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    while (true) {
        int n = rng() % 100 + 5;
        int m = rng() % 100 + 5;
        m += m & 1 ^ 1;

        for (int i = 1; i <= n; i++) {
            a[i] = rng() % m + 1;
        }

        if (solve()) {
            if (!check()) {
                cout << n << " " << m << endl;
                for (int i = 1; i <= n; i++) {
                    cout << a[i] << " ";
                }
                cout << endl;
                break;
            } else {
                cout << "- ok" << endl;
            }
        }
    }

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}