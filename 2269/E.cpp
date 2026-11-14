#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;
const int V = 1 << 18;

int pos[V];
int tag[V];
int timer_id = 0;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[0] = INF;
    a[n + 1] = INF;

    vector<int> L(n + 1), R(n + 1);
    stack<int> stk;

    stk.push(0);

    for (int i = 1; i <= n; i++) {
        while (a[stk.top()] <= a[i]) {
            stk.pop();
        }

        L[i] = stk.top() + 1;
        stk.push(i);
    }

    while (!stk.empty()) stk.pop();

    stk.push(n + 1);

    for (int i = n; i >= 1; i--) {
        while (a[stk.top()] < a[i]) {
            stk.pop();
        }

        R[i] = stk.top() - 1;
        stk.push(i);
    }

    vector<int> pref(n + 1);

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ a[i];
    }

    auto check = [&](int M) -> bool {

        vector<int> xrp(n + 1);

        for (int i = 0; i <= n; i++) {
            xrp[i] = pref[i] & M;
        }

        vector<int> nxt(n + 1);
        vector<int> prv(n + 1);

        ++timer_id;

        for (int i = n; i >= 0; i--) {
            int v = xrp[i];

            if (tag[v] == timer_id) {
                nxt[i] = pos[v];
            }
            else {
                nxt[i] = n + 1;
            }

            tag[v] = timer_id;
            pos[v] = i;
        }

        ++timer_id;

        for (int i = 0; i <= n; i++) {
            int v = xrp[i];

            if (tag[v] == timer_id) {
                prv[i] = pos[v];
            }
            else {
                prv[i] = -1;
            }

            tag[v] = timer_id;
            pos[v] = i;
        }

        ++timer_id;

        for (int j = n; j >= 1; j--) {
            int v = xrp[j];

            tag[v] = timer_id;
            pos[v] = j;
        }

        for (int i = 1; i <= n; i++) {

            int lenL = i - L[i] + 1;
            int lenR = R[i] - i + 1;

            if (lenL <= lenR && (a[i] & M) == M) {

                for (int x = L[i] - 1; x <= i - 1; x++) {

                    int target = M ^ xrp[x];

                    int y;

                    if (tag[target] == timer_id) {
                        y = pos[target];
                    }
                    else {
                        y = n + 1;
                    }

                    if (x == i - 1 && y == i) {
                        y = nxt[y];
                    }

                    if (y <= R[i]) {
                        return true;
                    }
                }
            }

            int v = xrp[i];

            tag[v] = timer_id;
            pos[v] = nxt[i];
        }

        ++timer_id;

        for (int j = 0; j <= n - 1; j++) {
            int v = xrp[j];

            tag[v] = timer_id;
            pos[v] = j;
        }

        for (int i = n; i >= 1; i--) {

            int lenL = i - L[i] + 1;
            int lenR = R[i] - i + 1;

            if (lenR < lenL && (a[i] & M) == M) {

                for (int y = i; y <= R[i]; y++) {

                    int target = M ^ xrp[y];

                    int x;

                    if (tag[target] == timer_id) {
                        x = pos[target];
                    }
                    else {
                        x = -1;
                    }

                    if (y == i && x == i - 1) {
                        x = prv[x];
                    }

                    if (x >= L[i] - 1) {
                        return true;
                    }
                }
            }

            int id = i - 1;
            int v = xrp[id];

            tag[v] = timer_id;
            pos[v] = prv[id];
        }

        return false;
    };

    int ans = 0;

    for (int b = 17; b >= 0; b--) {
        int M = ans | (1 << b);

        if (check(M)) {
            ans = M;
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