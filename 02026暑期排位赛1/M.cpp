#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

mt19937 rng(random_device{}());

string solve0(string &s, string &t, int n) {
    vector<int> ss(n + 2), tt(n + 2);
    for (int i = 1; i <= n; i++) {
        ss[i] = ss[i - 1] ^ (s[i] - '0');
        tt[i] = tt[i - 1] ^ (t[i] - '0');
    }

    ss[n + 1] = ss[n], tt[n + 1] = tt[n];
    if (tt[n + 1] != ss[n + 1]) {
        for (int i = 0; i <= n + 1; i++) {
            tt[i] ^= 1;
        }
    }

    // for (int i = 0; i <= n + 1; i++) {
    //     cout << ss[i];
    // }
    // cout << endl;

    // for (int i = 0; i <= n + 1; i++) {
    //     cout << tt[i];
    // }
    // cout << endl;

    int cntss = accumulate(ss.begin(), ss.end(), 0);
    int cnttt = accumulate(tt.begin(), tt.end(), 0);

    return (cntss == cnttt ? "YES" : "NO");
}

string solve_brute(string &s, string &t, int n) {
    set<string> seen;
    queue<string> q;
    q.push(s);
    seen.insert(s);

    bool found = false;
    while (q.size() > 0) {
        string cur = q.front();
        q.pop();

        if (cur == t) {
            found = true;
            break;
        }

        string nxt = cur;

        for (int i = 1; i <= n; i++) {
            if (nxt[i] == '0') continue;
            if (i > 1) nxt[i - 1] = '0' + !(nxt[i - 1] - '0');
            if (i < n) nxt[i + 1] = '0' + !(nxt[i + 1] - '0');
            if (!seen.count(nxt)) {
                q.push(nxt);
                seen.insert(nxt);
            }
            if (i > 1) nxt[i - 1] = '0' + !(nxt[i - 1] - '1');
            if (i < n) nxt[i + 1] = '0' + !(nxt[i + 1] - '1');
        }
    }

    return (found ? "YES" : "NO");
}

void solve() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    s = '.' + s, t = '.' + t;

    cout << solve_brute(s, t, n) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        int n = 3;
        string s = ".", t = ".";
        for (int i = 1; i <= n; i++) {
            s += '0' + (rng() & 1);
            t += '0' + (rng() & 1);
        }

        cout << s << " " << t << " ? ";

        bool pred = (solve0(s, t, n) == solve_brute(s, t, n));
        cout << (pred ? "OK" : "WRONG") << endl;
        if (!pred) break;
    }

    // int t = 1;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    return 0;
}