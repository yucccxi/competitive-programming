#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end(), [&](const string &s, const string &t) -> bool {
        if (s.size() != t.size()) return s.size() > t.size();
        ll sv = stoll(s);
        ll tv = stoll(t);
        return sv > tv;
    });

    vector<string> cand1, cand2;
    for (int i = 1; i < k; i++) {
        cand1.push_back(a[i]);
        cand2.push_back(a[i]);
    }
    cand1.push_back(a[k]);

    ll maxv = 0;
    for (int i = k; i <= n; i++) {
        maxv = max(maxv, stoll(a[i]));
    }

    cand2.push_back(to_string(maxv));

    sort(cand1.begin(), cand1.end(), [&](const string &s, const string &t) -> bool {
        return s + t > t + s;
    });

    sort(cand2.begin(), cand2.end(), [&](const string &s, const string &t) -> bool {
        return s + t > t + s;
    });

    string p, q;
    for (string &s : cand1) p += s;
    for (string &s : cand2) q += s;

    auto trim = [&](const string str) -> string {
        string ans;
        bool f = false;
        for (char ch : str) {
            if (ch == '0' && !f) {
                continue;
            }
            if (ch != '0') f = true;
            ans += ch;
        }

        if (ans.size() == 0) ans = "0";

        return ans;
    };

    p = trim(p);
    q = trim(q);

    if (p.size() != q.size()) {
        cout << (p.size() > q.size() ? p : q) << endl;
    } else {
        cout << max(p, q) << endl;
    }
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