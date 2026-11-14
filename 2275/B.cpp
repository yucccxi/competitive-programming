#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n;
    cin >> n;

    string s; cin >> s;
    s = '.' + s;

    vector<bool> marked(n + 1, false);
    stack<int> st;

    for (int i = 1; i <= n; i++) {
        char c = s[i];
        if (c == '1') {
            st.push(i);
        } else if (c == '2') {
            if (st.size() > 0) {
                int tp = st.top();
                st.pop();
                marked[tp] = true;
            } else {
                marked[i] = true;
            }
        } else if (c == '3') {
            marked[i] = true;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!marked[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
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