#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define int long long

const int MOD = 998244353;

ll modpow(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mx;
    vector<int> persl(1), persr(1);

    mx = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > mx) {
            persl.push_back(a[i]);
            mx = a[i];
        }
    }

    mx = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] > mx) {
            persr.push_back(a[i]);
            mx = a[i];
        }
    }

    reverse(persr.begin() + 1, persr.end());

    int tot_mx = persl.back();

    vector<int> dpl(n + 1), dpr(n + 1);
    vector<int> cl(persl.size()), cr(persr.size() + 1);
    cl[0] = 1, cr[persr.size()] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = persl.size() - 1; j >= 1; j--) {
            // 注意细节
            // =======================
            if (a[i] <= persl[j]) {
                cl[j] *= 2;
                cl[j] %= MOD;
            }

            if (a[i] == persl[j]) {
                cl[j] += cl[j - 1];
            }
            // =======================

            cl[j] %= MOD;
        }

        if (a[i] == tot_mx) {
            dpl[i] = cl[persl.size() - 2];
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = persr.size() - 1; j >= 1; j--) {
            if (a[i] <= persr[j]) {
                cr[j] *= 2;
                cr[j] %= MOD;
            }

            if (a[i] == persr[j]) {
                cr[j] += cr[j + 1];
            }

            cr[j] %= MOD;
        }

        if (a[i] == tot_mx) {
            dpr[i] = cr[2];
        }
    }

    ll ans = 0;
    ll contr = 0;
    for (int r = 1; r <= n; r++) {
        ans = (ans + contr * dpr[r]) % MOD;
        ans = (ans + dpl[r] * dpr[r]) % MOD;
        contr = (contr * 2 + dpl[r]) % MOD;
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