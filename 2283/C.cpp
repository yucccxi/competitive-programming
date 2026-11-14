#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

map<int, vector<int>> mp;

void solve() {
    int n; cin >> n;
    int msb = 31 - __builtin_clz(n);
    int k = (1 << (msb + 1)) - 1;

    k <<= 1;

    int xr = 0;
    for (int i = 1; i <= n; i++) {
        xr ^= i;
    }

    for (int i = 1; i <= n; i++) {
        int cxr = xr;
        cxr ^= i;
        cxr ^= i * 2;

        if (cxr == k || cxr == (k | 1)) {
            for (int _ = 1; _ <= n; _++) {
                if (_ == i) {
                    cout << 1 << " ";
                } else {
                    cout << 0 << " ";
                }
            }

            cout << endl;

            return;
        }

        int need = k ^ cxr;
        vector<int> &vec = mp[need];
        for (int j : vec) {
            if (j > n) break;
            if (j != i) {
                for (int _ = 1; _ <= n; _++) {
                    if (_ == i || _ == j) {
                        cout << 1 << " ";
                    } else {
                        cout << 0 << " ";
                    }
                }

                cout << endl;

                return;
            }
        }

        need = (k | 1) ^ cxr;
        vector<int> &vec2 = mp[need];
        for (int j : vec2) {
            if (j > n) break;
            if (j != i) {
                for (int _ = 1; _ <= n; _++) {
                    if (_ == i || _ == j) {
                        cout << 1 << " ";
                    } else {
                        cout << 0 << " ";
                    }
                }

                cout << endl;

                return;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 200000; i++) {
        mp[i ^ (i << 1)].push_back(i);
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}