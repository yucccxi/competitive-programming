#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int INF = 0x3f3f3f3f;
const int MOD = 998244353 ;

const int MAXN = 1e5 + 5;
const int MAXQ = 3e5 + 5;

int n, q;
int a[MAXN], qid[MAXQ];
string s, t[MAXQ];

ll pref[MAXN], ppref[MAXN];
ll prefmn[MAXN], suffmx[MAXN];

map<string, int> mp;
map<int, vector<int>> idx;

int trie[MAXQ][26], fail[MAXQ], endp[MAXQ], id;
vector<int> all[MAXQ];

pair<ll, ll> ans[MAXQ];

void insert(string &s, int v) {
    int p = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[p][c] == 0) {
            trie[p][c] = ++id;
        }
        p = trie[p][c];
    }

    endp[p] = v;
}

void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (trie[0][i] > 0) {
            q.push(trie[0][i]);
        }
    }

    while (q.size() > 0) {
        int u = q.front();
        q.pop();

        all[u] = all[fail[u]];
        if (endp[u] > 0) all[u].push_back(endp[u]);

        for (int i = 0; i < 26; i++) {
            if (trie[u][i] == 0) {
                trie[u][i] = trie[fail[u]][i];
            } else {
                int v = trie[u][i];
                fail[v] = trie[fail[u]][i];
                q.push(v);
            }
        }
    }
}

void precompute() {

    for (int i = 1; i <= n; i++) {
        pref[i]  = pref[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        ppref[i]  = ppref[i - 1] + pref[i];
        ppref[i]  = (ppref[i] % MOD + MOD) % MOD;
    }

    prefmn[  0  ] = +0;
    suffmx[n + 1] = -LINF;
    for (int i = 1; i <= n; i++) {
        prefmn[i] = min(prefmn[i - 1], pref[i]);
    }

    for (int i = n; i >= 1; i--) {
        suffmx[i] = max(suffmx[i + 1], pref[i]);
    }
}

void solve() {
    cin >> n >> q;
    cin >> s; s = '.' + s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= q; i++) {
        cin >> t[i];

        auto it = mp.find(t[i]);
        if (it == mp.end()) {
            mp[t[i]] = i;
            qid[i] = i;
            insert(t[i], i);
        } else qid[i] = it->second;
    }

    build();
    precompute();

    int p = 0;
    for (int i = 1; i <= n; i++) {
        int c = s[i] - 'a';
        p = trie[p][c];
        for (int j : all[p]) {
            idx[j].push_back(i);
        }
    }

    for (int i = 1; i <= q; i++) {
        ll ansp = -LINF, ansq = 0;
        if (qid[i] == i) {
            int len = t[i].size();
            vector<int> &v = idx[i];
            v.push_back(n + 1);
            for (int _ = 0; _ < v.size() - 1; _++) {
                int j = v[_], k = v[_ + 1] - 1;
                ansp  = max(ansp, suffmx[j] - prefmn[j - len]);
                ansq += (ppref[k] - ppref[j - 1]) * (j - len + 1);
                ansq  = (ansq % MOD + MOD) % MOD;
                ansq -= ppref[j - len] * (k - j + 1);
                ansq  = (ansq % MOD + MOD) % MOD;
            }

            ans[i] = {ansp, ansq};
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[qid[i]].first << " " << ans[qid[i]].second << endl;
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