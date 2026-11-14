#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 2e5 + 5;

int spf[MAXN];

void sieve() {
    for (int i = 2; i < MAXN; i ++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i ++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << (spf[n + 1] == n + 1 ? "YES" : "NO") << endl;
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