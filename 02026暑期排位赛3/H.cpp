#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    string s; cin >> s;
    int n = s.size();
    s = '.' + s;

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};

    int cntc = 0, cntv = 0, cnty = 0, cntn = 0, cntg = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'Y') {
            cnty++;
        } else if (s[i] == 'N') {
            cntn++;
        } else if (s[i] == 'G') {
            cntg++;
        } else {
            bool v = false;
            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j]) {
                    v = true;
                    break;
                }
            }

            if (v) cntv++;
            else   cntc++;
        }
    }

    int ans = 0;

    // Y as a vowel
    for (int y = 0; y <= cnty; y++) {
        // NG as a whole
        for (int ng = 0; ng <= min(cntn, cntg); ng++) {
            int ncntc  = cntc + cntn + cntg - ng * 2 + cnty - y;
            int ncntng = ng;
            int ncntv  = cntv + y;
            
            int nans = 0, take;

            take = min(ncntv, ncntng / 2);
            nans += 5 * take;
            ncntv -= take;
            ncntng -= take * 2;

            take = min({ncntv, ncntng, ncntc});
            nans += 4 * take;
            ncntv  -= take;
            ncntc  -= take;
            ncntng -= take;
            
            take = min(ncntv, ncntc / 2);
            nans += 3 * take;
            ncntv -= take;
            ncntc -= take * 2;

            ans = max(ans, nans);
        }
    }

    cout << ans << endl;
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