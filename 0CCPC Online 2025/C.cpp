#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e5 + 5;

struct meta {
    int u, v, w;
    bool operator<(const meta &o) const {
        return w > o.w;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    multiset<int> st;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        x %= k;
        st.insert(x);
    }

    priority_queue<meta> pq;

    auto add = [&](int x) -> void {
        auto it = st.lower_bound(k - x);
        if (it == st.end()) it = st.begin();
        pq.push({x, *it, (x + *it) % k});
    };

    int x = *st.begin();
    st.erase(st.begin());
    add(x);

    ll ans = 0;
    
    while (pq.size() > 0) {
        meta tp = pq.top();
        pq.pop();

        auto it = st.find(tp.v);
        if (it == st.end()) continue;
        st.erase(it);

        ans += tp.w;

        if (st.size() > 0) {
            add(tp.u);
            add(tp.v);
        }
    }

    cout << ans << endl;
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