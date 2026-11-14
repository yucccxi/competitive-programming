#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 998244353;

struct node {
    ll cnt, sx, sy, sxy;
};

void add_transition(node &cur, const node &prev, int x, int y) {
    cur.cnt += prev.cnt;
    cur.sx  += prev.sx + x * prev.cnt;
    cur.sy  += prev.sy + y * prev.cnt;
    cur.sxy += prev.sxy + y * prev.sx + x * prev.sy + x * y * prev.cnt;
    cur.cnt %= MOD;
    cur.sx  %= MOD;
    cur.sy  %= MOD;
    cur.sxy %= MOD;
}

void solve() {
    ll n, d;
    cin >> n >> d;

    // carry, borrow
    node dp[2][2] {};
    dp[0][0].cnt = 1;
    for (int k = 0; k <= 60; k++) {
        node ndp[2][2] {};

        int nbit = n >> k & 1;
        int dbit = d >> k & 1;

        for (int carry = 0; carry <= 1; carry++) {
            for (int borrow = 0; borrow <= 1; borrow++) {
                const node &prev = dp[carry][borrow];
                int upper = (k == 60 ? 0 : 1);
                for (int x = 0; x <= upper; x++) {
                    int sum = x + dbit + carry;
                    int y       = sum & 1;
                    int ncarry  = sum >> 1;
                    int nborrow = (nbit < x + borrow);

                    add_transition(ndp[ncarry][nborrow], prev, x, y);
                }
            }
        }

        memcpy(dp, ndp, sizeof(dp));
    }

    cout << dp[0][0].sxy << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << v << endl;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0; 
}