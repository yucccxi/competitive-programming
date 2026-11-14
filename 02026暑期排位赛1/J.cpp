#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct E {
    ll v;
    bool operator<(const E &o) const {
        return __builtin_ctzll(v) > __builtin_ctzll(o.v);
    }

    E(ll u) : v(u) {};
};

void solve() {
    int n; cin >> n;
    priority_queue<E> pq;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    for (int i = 1; i <= n - 1; i++) {
        ll u = pq.top().v; pq.pop();
        ll v = pq.top().v; pq.pop();
        pq.push(E(__gcd(u, v) * 2));
    }

    cout << pq.top().v << endl;
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