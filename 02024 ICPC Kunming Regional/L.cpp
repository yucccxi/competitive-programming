#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a, b(m);

    int atk = 0, expl = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        if (h == 1) {
            ++expl;
        } else {
            ++atk;
            a.push_back(h - 1);
        }
    }

    atk += (expl > 0);

    for (int &h : b) {
        cin >> h;
    }

    n = a.size();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    while (j < m) {
        if (i < n && a[i] <= expl) {
            ++i;
            ++expl;
        } else if (b[j] <= expl) {
            ++j;
            ++expl;
        } else {
            int need = b[j] - expl;

            if (atk < need) {
                cout << "No" << endl;
                return;
            }

            atk -= need;
            ++j;
            ++expl;
        }
    }

    cout << "Yes" << endl;
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