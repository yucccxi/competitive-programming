#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> basis(n, vector<int>(m));

    auto insert = [&](vector<int> &vec, int x) -> bool {
        for (int i = m - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (vec[i] == 0) {
                    vec[i] = x;
                    return true;
                }
                x ^= vec[i];
            }
        }
        return false;
    };

    auto belong = [&](const vector<int> &vec, int x) -> bool {
        for (int i = m - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (!vec[i]) return false;
                x ^= vec[i];
            }
        }
        return true;
    };

    auto contains = [&](const vector<int> &vec1, const vector<int> &vec2) -> bool {
        for (int i = 0; i < m; i++) {
            if (!belong(vec2, vec1[i])) return false;
        }
        return true;
    };

    vector<int> freq(1 << m);
    vector<int> global(m);

    for (int i = 0; i < n; i++) {
        int cnt; cin >> cnt;
        vector<int> a(cnt);
        
        int r = 0;
        for (int &x : a) {
            cin >> x;
            freq[x]++;
            r += insert(basis[i], x);
        }

        vector<int> idx;
        for (int j = 0; j < m; j++) {
            if (basis[i][j] > 0) idx.push_back(j);
        }

        assert(idx.size() == r);

        vector<int> inc(m);
        if ((cnt << 1) >= (1 << r)) {
            set<int> st;
            for (int j = 0; j < (1 << r); j++) {
                int v = 0;
                for (int k = 0; k < r; k++) {
                    if (j >> k & 1) {
                        v ^= basis[i][idx[k]];
                    }
                }
                st.insert(v);
            }

            for (int x : a) {
                st.erase(x);
            }

            for (int x : st) {
                insert(inc, x);
            }
        } else inc = basis[i];

        for (int i = 0; i < m; i++) {
            if (inc[i] > 0) {
                insert(global, inc[i]);
            }
        }
    }

    while (true) {
        bool changed = false;

        for (int i = 0; i < n; i++) {
            if (contains(global, basis[i]) || contains(basis[i], global)) {
                continue;
            }

            for (int j = 0; j < m; j++) {
                changed |= insert(global, basis[i][j]);
            }
        }

        if (!changed) break;
    }

    vector<int> idx;
    for (int i = 0; i < m; i++) {
        if (global[i] > 0) {
            idx.push_back(i);
        }
    }

    int r = idx.size();

    set<int> ans;
    for (int i = 0; i < (1 << r); i++) {
        int v = 0;
        for (int j = 0; j < r; j++) {
            if (i >> j & 1) {
                v ^= global[idx[j]];
            }
        }
        ans.insert(v);
    }

    for (int i = 0; i < (1 << m); i++) {
        if (freq[i] == n) {
            ans.erase(i);
        }
    }

    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
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