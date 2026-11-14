#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 2e5 + 5;

struct ac_automation {
    int trie[MAXN][26], fail[MAXN], cnt[MAXN], id;

    void insert(string &s) {
        int p = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (trie[p][c] == 0) {
                trie[p][c] = ++id;
            }
            p = trie[p][c];
        }
        cnt[p]++;
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
            for (int i = 0; i < 26; i++) {
                if (trie[u][i] == 0) {
                    trie[u][i] = trie[fail[u]][i];
                } else {
                    int v = trie[u][i];
                    fail[trie[u][i]] = trie[fail[u]][i];
                    q.push(v);
                    cnt[v] += cnt[fail[v]];
                }
            }
        }
    }

    ac_automation() {
        memset(trie, 0, sizeof(trie));
        memset(fail, 0, sizeof(fail));
        memset(cnt, 0, sizeof(cnt));
        id = 0;
    }
};

int n;
string s, t;

ac_automation fw, bw;
int st[MAXN], ed[MAXN];

void solve() {
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        fw.insert(t);
        reverse(t.begin(), t.end());
        bw.insert(t);
    }

    fw.build();
    bw.build();

    int sz = s.size(), p;

    p = 0;
    for (int i = 0; i < sz; i++) {
        int c = s[i] - 'a';
        p = fw.trie[p][c];
        ed[i] = fw.cnt[p];
    }

    p = 0;
    for (int i = sz - 1; i >= 0; i--) {
        int c = s[i] - 'a';
        p = bw.trie[p][c];
        st[i] = bw.cnt[p];
    }

    ll ans = 0;

    for (int i = 0; i < sz - 1; i++) {
        ans += (ll)ed[i] * st[i + 1];
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