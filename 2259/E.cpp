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

    int pos0 = 0, posn1 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] ==  0) pos0  = i;
        if (a[i] == -1) posn1 = i;
    }

    if (pos0 == 0 && posn1 == 0) {
        cout << -1 << endl;
        return;
    }

    vector<int> idx;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            idx.push_back(i);
        }
    }

    if (pos0 == 0) {
        pos0 = idx.back();
        a[pos0] = 0;
        idx.pop_back();
    }

    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; i++) {
        if (a[i] != -1 && a[i] != 0) {
            vec.push_back({a[i], i});
        }
    }

    sort(vec.begin(), vec.end());

    set<pair<int, int>> st;
    st.insert({0, pos0});

    vector<int> ans(n + 1);

    for (int i = 0; i < vec.size(); i++) {
        auto &[dist, pos] = vec[i];
        auto it = st.lower_bound({dist - 1, 0});
        if (it == st.end()) {
            if (idx.size() == 0) {
                cout << -1 << endl;
                return;
            }

            i--;
            int d = st.rbegin()->first + 1;
            ans[idx.back()] = d;
            st.insert({d, idx.back()});
            idx.pop_back();
        } else {
            ans[pos] = dist;
            st.insert({dist, pos});
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (!!ans[i]);
    }
    cout << endl;
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