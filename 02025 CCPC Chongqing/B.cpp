#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MOD = 1e9 + 7;

ll n, k;
ll t[1005], dp[105];

void solve() {
    cin >> n >> k;
    ll maxt = 0;
    for (int i = 1; i < k; i++) {
        cin >> t[i];
        maxt = max(maxt, t[i]);
    }

    for (int i = 0; i < maxt; i++) {
        dp[i + 1] = (dp[i] + 1) % MOD;
        for (int j = 1; j < k; j++) {
            if (t[j] <= i) {
                dp[i + 1] += dp[i] - dp[i - t[j]] + 1;
                dp[i + 1] %= MOD;
            }
        }
    }

    vector<vector<ll>> T(maxt + 2, vector<ll>(maxt + 2));
    T[0][0] += k;
    T[maxt + 1][0] += k;

    for (int i = 1; i < k; i++) {
        --T[t[i]][0];
    }

    for (int i = 0; i <= maxt - 1; i++) {
        T[i][i + 1] = 1;
    }

    T[maxt + 1][maxt + 1] = 1;

    vector<ll> mat(maxt + 2);
    for (int i = 0; i <= maxt; i++) {
        mat[i] = dp[maxt - i];
    }

    mat[maxt + 1] = 1;

    ll need = n - maxt;
    if (need <= 0) {
        cout << dp[n] << endl;
        return;
    }

    auto matmul = [&](const vector<vector<ll>> &vec1, const vector<vector<ll>> &vec2) -> vector<vector<ll>> {
        int n = vec1.size();
        vector<vector<ll>> ret(n, vector<ll>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ret[i][j] += vec1[i][k] * vec2[k][j];
                    ret[i][j] = ((ret[i][j] % MOD) + MOD) % MOD;
                }
            }
        }

        return ret;
    };

    auto matpow = [&](const vector<vector<ll>> &vec, int pw) -> vector<vector<ll>> {
        int n = vec.size();
        vector<vector<ll>> ret(n, vector<ll>(n));
        vector<vector<ll>> base = vec;
        for (int i = 0; i < n; i++) {
            ret[i][i] = 1;
        }

        while (pw > 0) {
            if (pw & 1) {
                ret = matmul(ret, base);
            }

            base = matmul(base, base);
            pw >>= 1;
        }

        return ret;
    };

    vector<vector<ll>> nT = matpow(T, need);

    ll ans = 0;
    for (int i = 0; i <= maxt + 1; i++) {
        ans += mat[i] * nT[i][0];
        ans = ((ans % MOD) + MOD) % MOD;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}