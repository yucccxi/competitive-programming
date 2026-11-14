#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int n, N;
int pw[17], dp[43046721], fst[43046721];

void precompute() {

    pw[0] = 1;
    for (int i = 1; i <= 16; i++) {
        pw[i] = pw[i - 1] * 3;
    }

    memset(fst, -1, sizeof(fst));
    for (int i = 0; i < 43046721; i++) {
        int val = i, j = 0;
        while (val > 0) {
            if (val % 3 == 2) {
                fst[i] = j;
                break;
            }

            val /= 3;
            ++j;
        }
    }
}

void solve() {
    cin >> n;
    N = 1 << n;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;

        int state = 0;
        for (int bit = 0; bit < n; bit++) {
            if (i >> bit & 1) {
                state += pw[bit];
            }
        }

        dp[state] = x;
    }

    for (int mask = 0; mask < pw[n]; ++mask) {
        int j = fst[mask];
        if (j != -1) {
            dp[mask] += dp[mask - pw[j]];
            dp[mask] += dp[mask - pw[j] * 2];
        }
    }

    int ans = 0;
    for (int i = 0; i < pw[n]; i++) {
        ans ^= dp[i];
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}