#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 5e5 + 5;

const ll B1 = 131, M1 = 1e9 + 7;
const ll B2 = 13331, M2 = 1e9 + 9;

string s, t;
int n, m;

ll hash1[MAXN], hash2[MAXN];
ll pw1[MAXN], pw2[MAXN];

vector<string> part(1);
vector<ll> hpart1(1), hpart2(1);

ll dp[MAXN][12];

void precompute() {
    pw1[0] = 1, pw2[0] = 1;
    for (int i = 1; i <= m; i++) {
        pw1[i] = pw1[i - 1] * B1 % M1;
        pw2[i] = pw2[i - 1] * B2 % M2;
    }

    for (int i = 1; i <= m; i++) {
        hash1[i] = (hash1[i - 1] * B1 + t[i]) % M1;
        hash2[i] = (hash2[i - 1] * B2 + t[i]) % M2;
    }
}

ll chash1(int l, int r) {
    ll ret = (hash1[r] - hash1[l - 1] * pw1[r - l + 1] % M1);
    if (ret < 0) ret += M1;
    return ret;
}

ll chash2(int l, int r) {
    ll ret = (hash2[r] - hash2[l - 1] * pw2[r - l + 1] % M2);
    if (ret < 0) ret += M2;
    return ret;
}

void solve() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    s = '.' + s, t = '.' + t;

    precompute();

    int l = 1, cnt = 0;
    while (l <= n) {
        while (l <= n && s[l] == '*') l++;
        if (l == n + 1) break;
        int r = l + 1;
        while (r <= n && s[r] != '*') r++;

        string cur;
        ll u = 0, v = 0;
        for (int i = l; i < r; i++) {
            cur += s[i];
            u = (u * B1 + s[i]) % M1;
            v = (v * B2 + s[i]) % M2;
        }

        part.push_back(cur);
        hpart1.push_back(u);
        hpart2.push_back(v);
        cnt++;

        l = r;
    }

    if (cnt == 0) {
        cout << (ll)(m + 1) * m / 2 << endl;
        return;
    }

    bool prev = (s[1] == '*');
    bool tail = (s[n] == '*');

    
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