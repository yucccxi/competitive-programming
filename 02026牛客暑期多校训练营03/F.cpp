#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int MOD = 998244353;

int n, m;

int cnt = 0;
vector<int> all[128], cur;

void dfs(int pos) {
    if (pos == n) {
        all[cnt++] = cur;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (pos == 0 || cur[pos - 1] != i) {
            cur[pos] = i;
            dfs(pos + 1);
        }

        cur[pos] = -1;
    }
}

vector<vector<ll>> mul(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2) {
    vector<vector<ll>> ans(cnt, vector<ll>(cnt));
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            for (int k = 0; k < cnt; k++) {
                ans[i][j] += mat1[i][k] * mat2[k][j];
                ans[i][j] %= MOD;
            }
        }
    }

    return ans;
}

vector<vector<ll>> matpow(vector<vector<ll>> &mat, int k) {
    vector<vector<ll>> ans(cnt, vector<ll>(cnt));
    for (int i = 0; i < cnt; i++) {
        ans[i][i] = 1;
    }

    while (k > 0) {
        if (k & 1) {
            ans = mul(ans, mat);
        }

        mat = mul(mat, mat);
        k >>= 1;
    }

    return ans;
}

ll modpow(ll a, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;
        n >>= 1;
    }

    return ans;
}

int mapper[6][3] = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

void solve() {
    cin >> n >> m;

    if (n == 1) {
        cout << 3 * modpow(2, m - 1) % MOD << endl;
        return;
    }

    cur.resize(n);
    cur[0] = 0, cur[1] = 1;
    dfs(2);

    vector<vector<ll>> mat(cnt, vector<ll>(cnt));
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            for (int p = 0; p < 6; p++) {
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (all[i][k] == mapper[p][all[j][k]]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) mat[i][j]++;
            }
        }
    }

    vector<vector<ll>> pmat = matpow(mat, m - 1);
    ll ans = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            ans += pmat[i][j];
        }
    }

    ans *= 6;
    ans %= MOD;

    cout << ans << endl;
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