#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 2e5 + 5;
const int INF  = 1e9;

int spf[MAXN];
vector<int> pf[MAXN];

void sieve() {
    for (int i = 1; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i < MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = (ll)i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    for (int i = 2; i < MAXN; i++) {
        int x = i;
        while (x > 1) {
            int f = spf[x];
            while (spf[x] == f) {
                x /= f;
            }

            pf[i].push_back(f);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 1, INF);

    for (int i = 0; i <= k; i++) {
        cnt[i] = 0;
    }
    
    for (int i = k + 1; i <= n; i++) {
        for (int f : pf[i]) {
            cnt[i] = min(cnt[i], f * cnt[i / f] + 1);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ans += cnt[x];
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    sieve();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}