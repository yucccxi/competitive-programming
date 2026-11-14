#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

ll best(vector<ll> &a, int n, int m) {
    ll mine = a[1] + m;
    ll cnt = (a[2] > mine);
    for (int i = 2; i <= n; i++) {
        int u = 2 * i - 1, v = 2 * i;
        if (a[u] > a[v]) swap(u, v);

        if (a[u] > mine) {
            cnt += 2;
            continue;
        }

        // a[u] <= mine
        if (a[v] > mine) {
            cnt += 1;
            continue;
        }

        if (a[v] == mine) {
            if (m > mine - a[u]) {
                cnt += 1;
            }
            continue;
        }

        // a[u] <= mine && a[v] <= mine
        if (m > 2 * mine - (a[u] + a[v])) {
            cnt += 1;
        }
    }

    return cnt;
}

ll worst(vector<ll> &a, int n, int m) {
    ll mine = a[1];
    ll cnt = (a[2] + m > mine);
    for (int i = 2; i <= n; i++) {
        int u = i * 2 - 1, v = i * 2;
        if (a[u] > a[v]) swap(u, v);
        if (a[u] >= mine) {
            cnt += 2;
            continue;
        }

        // a[u] < mine
        if (a[v] > mine) {
            if (m > mine - a[u]) {
                cnt += 2;
            } else {
                cnt += 1;
            }
            continue;
        }

        // a[v] <= mine
        if (a[v] == mine) {
            cnt += 1;
            if (a[u] + m - 1 >= mine) {
                cnt += 1;
            }
            continue;
        }

        if (m > 2 * mine - (a[u] + a[v])) {
            cnt += 2;
        } else if (m > mine - a[v]) {
            cnt += 1;
        }
    }

    return cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }

    cout << best(a, n, m) << " " << worst(a, n, m) << endl;
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