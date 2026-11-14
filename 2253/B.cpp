#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> segs;
    int l = 1;
    while (l <= n) {
        int r = l;
        while (r <= n && a[r] == a[l]) {
            r++;
        }

        segs.push_back({a[l], r - l});
        l = r;
    }

    int m = segs.size();
    int maxinc = 0;

    for (int i = 0; i < m - 1; i++) {
        if (segs[i].second >= 2 && segs[i + 1].second >= 2) {
            maxinc = 2;
            break;
        }
    }

    if (maxinc < 2) {
        for (int i = 0; i < m; i++) {
            if (segs[i].second >= 2) {
                if (i + 1 < m) {
                    if (i + 2 >= m || segs[i].first != segs[i + 2].first) {
                        maxinc = max(maxinc, 1);
                    }
                }
                if (i - 1 >= 0) {
                    if (i - 2 < 0 || segs[i - 2].first != segs[i].first) {
                        maxinc = max(maxinc, 1);
                    }
                }
            }
        }
    }

    cout << m + maxinc << endl;
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