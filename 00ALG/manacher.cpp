#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    string _; cin >> _;
    int n = _.size();

    string s; cin >> s;
    s += '$';
    for (int i = 0; i < n; i++) {
    	s += _[i];
    	s += '$';
    }

    int m = 2 * n + 1;
    int M = 0, R = 0;
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
    	if (i > R) p[i] = 1;
    	else p[i] = min(p[2 * M - i], R - i + 1);
    	while (i - p[i] >= 0 && i + p[i] < m && s[i + p[i]] == s[i - p[i]]) {
    		++p[i];
    	}

    	if (i + p[i] - 1 > R) {
    		M = i;
    		R = i + p[i] - 1;
    	}
    }

    cout << *max_element(p.begin(), p.end()) - 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}