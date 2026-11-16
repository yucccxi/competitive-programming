#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
  	string s; cin >> s;
  	
  	string t;
  	t += '$';
  	for (char c : s) {
  		if (c == 'w') {
  			t += 'v';
  			t += '$';
  			t += 'v';
  			t += '$';
  		} else {
  			t += c;
  			t += '$';
  		}
  	}

  	vector<bool> good;

  	string spl;
  	for (char c : s) {
  		if (c == 'w') {
  			good.push_back(true);
  			spl += 'v';
  			good.push_back(false);
  			spl += 'v';
  		} else {
  			good.push_back(true);
  			spl += c;
  		}
  	}

  	good.push_back(true);

  	int m = t.size();
  	vector<int> p(m);
  	int M = 0, R = 0;
  	for (int i = 0; i < m; i++) {
  		if (i > R) p[i] = 1;
  		else       p[i] = min(p[2 * M - i], R - i + 1);
  		while (i - p[i] >= 0 && i + p[i] < m && t[i - p[i]] == t[i + p[i]]) {
  			++p[i];
  		}
  		if (i + p[i] - 1 > R) {
  			R = i + p[i] - 1;
  			M = i;
  		}
  	}

  	vector<pair<int, int>> intv;
  	for (int i = 1; i < m - 1; i++) {
  		int j = (i - 1) / 2;
  		int len = p[i] - 1;
  		if (t[i] == '$') {
  			if (len > 0)
  				intv.emplace_back(j - len / 2 + 1, j + len / 2);
  		} else {
  			intv.emplace_back(j - len / 2, j + len / 2);
  		}
  	}

  	int sz = spl.size();

  	int curPos;
    vector<int> nxtV(sz), prvV(sz);
    
    curPos = sz;
    for (int i = sz - 1; i >= 0; i--) {
    	if (spl[i] == 'v' && good[i] && good[i + 1]) {
    		curPos = i;
    	}
    	nxtV[i] = curPos;
    }

    curPos = -1;
    for (int i = 0; i < sz; i++) {
    	if (spl[i] == 'v' && good[i] && good[i + 1]) {
    		curPos = i;
    	}
    	prvV[i] = curPos;
    }

    vector<int> pos(sz + 1);
    for (int i = 0; i < sz; ++i) {
        pos[i + 1] = pos[i] + good[i];
    }

    int ans = 0, ansl = 0;

    for (auto &[l, r] : intv) {
	    int k = 0;

	    if (!good[l] && !good[r + 1]) {
	        k = 1;
	    } else if (!good[l] || !good[r + 1]) {
	        k = min(nxtV[l] - l + 1, r - prvV[r] + 1);
	    }

	    int nl = l + k;
	    int nr = r - k;
	    if (nl > nr) continue;

	    int len = pos[nr + 1] - pos[nl];
	    if (len > ans) {
	        ans = len;
	        ansl = pos[nl];
	    }
	}

    cout << s.substr(ansl, ans) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}