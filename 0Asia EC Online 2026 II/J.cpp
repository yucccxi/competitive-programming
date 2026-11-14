#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    map<string, int> mp;
    mp["WrongProblem"] = 100;
    mp["SameProblem"] = 30;
    mp["UnreasonableLimitForProblem"] = 5;
    mp["WeakTestsForProblem"] = 3;
    mp["BadProblem"] = 1;

    int n, p;
    cin >> n >> p;

    ll ans = 0;

    while (n--) {
        string s; cin >> s;
        if (s == "UnreasonableProblemArrangement") {
            ans += 10;
            continue;
        }

        if (s.back() >= 'A' && s.back() <= 'L') {
            s.pop_back();
            ans += mp[s];
        }
    }

    if (ans > p) {
        cout << "Joker" << endl;
    } else {
        cout << "Judger" << endl;
    }
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