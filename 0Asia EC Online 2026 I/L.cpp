#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int MAXN = 5e5 + 5;

int id = 0;
int trie[MAXN][26], cnt[MAXN];

ll f[MAXN], ans;

void insert(string &s, int idx) {
    ans += idx;
    int cur = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (trie[cur][c] == 0) {
            trie[cur][c] = ++id;
        }
        cur = trie[cur][c];
        cnt[cur]++;
        ans -= f[cnt[cur]] ^ cnt[cur];
        f[cnt[cur]] = max(f[cnt[cur]], i + 1LL);
        ans += f[cnt[cur]] ^ cnt[cur];
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        insert(s, i);
        cout << ans << endl;
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