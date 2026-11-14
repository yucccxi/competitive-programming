#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }

    a.push_back(INF);

    vector<int> segs;
    int cnt = 0;
    int prev = 0;
    for (int i = 1; i <= 2 * n + 1; i++) {
        if (a[i] > a[prev]) {
            segs.push_back(i - prev);
            prev = i;
            ++cnt;
        }
    }
    --cnt;

    vector<int> pref(cnt + 1);

    for (int i = 1; i <= cnt; i++) {
        pref[i] = pref[i - 1] + segs[i];
    }

    vector<int> pre(n + 1);
    vector<bool> dp(n + 1), ndp(n + 1);
    ndp[0] = dp[0] = true;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= n; j++) {
            ndp[j] = dp[j];
            if (j >= segs[i] && dp[j - segs[i]] && !ndp[j]) {
                ndp[j] = true;
                pre[j] = i;
            }
        }

        dp.swap(ndp);
    }

    if (!dp[n]) {
        cout << -1 << endl;
        return;
    }

    vector<int> all;

    int len = n;
    while (len > 0) {
        all.push_back(pre[len]);
        len -= segs[pre[len]];
    }

    sort(all.begin(), all.end());

    vector<int> ansl, ansr;

    int pos = 0;
    for (int i = 1; i <= cnt; i++) {
        if (pos < all.size() && i == all[pos]) {
            for (int j = pref[i] - segs[i] + 1; j <= pref[i]; j++) {
                ansl.push_back(a[j]);
            }
            pos++;
        } else {
            for (int j = pref[i] - segs[i] + 1; j <= pref[i]; j++) {
                ansr.push_back(a[j]);
            }
        }
    }

    assert(ansl.size() == ansr.size());

    for (int i = 0; i < ansl.size(); i++) {
        int x = ansl[i];
        cout << x;
        if (i != ansl.size() - 1) cout << " ";
    }
    cout << endl;

    for (int i = 0; i < ansr.size(); i++) {
        int x = ansr[i];
        cout << x;
        if (i != ansr.size() - 1) cout << " ";
    }
    cout << endl;
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