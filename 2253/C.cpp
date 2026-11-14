#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 2e9;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(x), b(y);
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < y; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    auto calc = [&](int r, int c) -> ll {
        int sza = min((int)a.size(), r);
        int szb = min((int)b.size(), c);
        int sztot = sza + szb;

        ll ans = 0;
        int ca = 0, cb = 0, tot = 0;

        int pa = a.size() - 1;
        int pb = b.size() - 1;

        while ((pa >= 0 || pb >= 0) && tot < sztot) {
            int val, type;

            if (pa >= 0 && pb >= 0) {
                if (a[pa] > b[pb]) {
                    val = a[pa--];
                    type = 0;
                } else if (b[pb] > a[pa]) {
                    val = b[pb--];
                    type = 1;
                } else {
                    val = a[pa];
                    pa--;
                    pb--;
                    type = 2;
                }
            } else if (pa >= 0) {
                val = a[pa--];
                type = 0;
            } else {
                val = b[pb--];
                type = 1;
            }

            if (type == 0) {
                if (ca < sza) {
                    ca++;
                    tot++;
                    ans += val;
                }
            } else if (type == 1) {
                if (cb < szb) {
                    cb++;
                    tot++;
                    ans += val;
                }
            } else {
                tot++;
                ans += val;
            }
        }

        return ans;
    };

    ll ans = max(calc(n - 1, m), calc(n, m - 1));
    cout << ans << endl;
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