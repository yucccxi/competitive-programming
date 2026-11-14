#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct side {
    ll p, n;
};

struct node {
    ll l, r;
    ll mx;
    side left, right, top, bottom;
};

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    {
        bool f = false;
        int pos = 1;
        vector<bool> prev(n + 2);
        for (int i = 1; i <= n - 1; i++) {
            prev[p[i]] = true;
            while (prev[pos]) ++pos;

            if (i == pos - 1) { f = true; break; }
        }

        if (!f) {
            for (int i = 1; i <= n; i++) {
                p[i] = n - p[i] + 1;
            }
        }
    }

    stack<node> stk;
    for (int i = 1; i <= n; i++) {
        node cur;
        cur.mx = 0;
        cur.l = cur.r = p[i];
        cur.left = cur.right = cur.top = cur.bottom = {0, 0};
        stk.push(cur);

        while (stk.size() >= 2) {
            node u, v;
            v = stk.top(); stk.pop();
            u = stk.top(); stk.pop();

            ll lenu = u.r - u.l + 1;
            ll lenv = v.r - v.l + 1;
            if (u.r + 1 == v.l) {
                node c;
                c.l = u.l, c.r = v.r;

                ll tr   = max(u.right.p + lenv, v.top.n + lenu + lenv - 1);
                c.top.p = max(u.top.p, tr + lenv + lenu - 1);
                c.top.n = max(u.top.n, tr - (lenv - 1) - lenu);

                c.right.p = max(tr, v.right.p + lenu);
                c.right.n = max(tr, v.right.n - lenu);

                ll bl    = max(u.bottom.p + lenv, v.left.n + lenu + lenv - 1);
                c.left.p = max(u.left.p, bl + lenv + lenu - 1);
                c.left.n = max(u.left.n, bl - (lenv - 1) - lenu); 

                c.bottom.p = max(bl, v.bottom.p + lenu);
                c.bottom.n = max(bl, v.bottom.n - lenu);

                c.mx = max(bl, tr);

                stk.push(c);
            } else if (v.r + 1 == u.l) {
                node c;
                c.l = v.l, c.r = u.r;

                ll tl    = max(u.left.p + lenv, v.top.p + lenu);
                c.left.p = max(tl, v.left.p);
                c.left.n = max(tl, v.left.n);

                c.top.p = max(tl, u.top.p + lenv);
                c.top.n = max(tl, u.top.n - lenv);

                ll br      = max(v.right.n + lenu + lenv - 1, u.bottom.n + lenu + lenv - 1);
                c.bottom.p = max(v.bottom.p, br + lenv + lenu - 1);
                c.bottom.n = max(v.bottom.n, br - lenv - (lenu - 1));

                c.right.p = max(u.right.p, br + lenu + lenv - 1);
                c.right.n = max(u.right.n, br - lenu - (lenv - 1));

                c.mx = max(br, tl);

                stk.push(c);
            } else {
                stk.push(u);
                stk.push(v);
                break;
            }
        }
    }

    if (stk.size() != 1) {
        cout << -1 << endl;
    } else {
        cout << stk.top().mx << endl;
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