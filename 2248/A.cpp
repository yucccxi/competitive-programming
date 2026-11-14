#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

string del(string s, int i, int j) {
    string ret;
    for (int u = 0; u < s.size(); u++) {
        if (u != i && u != j) {
            ret.push_back(s[u]);
        }
    }

    return ret;
}

void solve() {
    string s; cin >> s;
    vector<int> cnt[2];
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - '0'].push_back(i);
    }

    string ans = "";

    for (int z : cnt[0]) {
        string cur = "";
        for (int o : cnt[1]) {
            string ret = del(s, z, o);
            if (cur == "" || ret < cur) {
                cur = ret;
            }
        }

        if (ans == "" || cur > ans) {
            ans = cur;
        }
    }

    // 01010000010100100101
    // 01010000010100100101

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