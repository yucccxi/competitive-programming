#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e6 + 5;
const int MAXV = 1e6 + 5;

int n;
int a[MAXN];

ll cnt, tot, ans;

int pos[MAXV], nxt[MAXV];
bitset<MAXV> seen;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n; i >= 1; i--) {
        nxt[i] = (pos[a[i]] == 0 ? n + 1 : pos[a[i]]);
        pos[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cnt += !seen[a[i]];
        tot += cnt;
        seen[a[i]] = true;
    }

    for (int i = 1; i <= n; i++) {
        ans += tot;
        tot -= nxt[i] - i;
    }

    ans = (ans - n) * 2 + n;

    cout << (double)ans / ((ll)n * n) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}