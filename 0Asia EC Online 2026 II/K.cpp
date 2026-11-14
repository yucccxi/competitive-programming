#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    vector<int> missing;

    for (int i = 0; i <= n + 5; i++) {
        if (cnt.find(i) == cnt.end()) {
            missing.push_back(i);
        }
    }

    map<int, int> mem;

    ll tot = 0;

    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        auto it = mem.find(k);
        if (it != mem.end()) {
            tot ^= it->second;
            continue;
        }

        ll ans = -1;
        ll ub  = INF;
        for (ll x : missing) {

            if (x > k) {
                ans = x;
                break;
            }

            if (k & 1) {
                if (x <= k / 2) {
                    int c = cnt[k - x];
                    if (c == 0) {
                        ans = x;
                        break;
                    } else if (c == 1) {
                        ub = min(ub, k - x);
                    }
                } else {
                    int c = cnt[k - x];
                    assert(c > 0);
                    if (c == 1) {
                        ans = x;
                        break;
                    }
                }
            } else {
                if (x == k / 2) {
                    if (cnt[x] == 0) {
                        ans = x;
                        break;
                    }
                } else if (x < k / 2) {
                    int c = cnt[k - x];
                    if (c == 0) {
                        ans = x;
                        break;
                    } else if (c == 1) {
                        ub = min(ub, k - x);
                    }
                } else {
                    int c = cnt[k - x];
                    assert(c > 0);
                    if (c == 1) {
                        ans = x;
                        break;
                    }
                }
            }
        }

        if (ans == -1) ans = ub;
        if (ans > ub) ans = ub;
        mem[k] = ans;
        tot ^= ans;
    }

    cout << tot << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}