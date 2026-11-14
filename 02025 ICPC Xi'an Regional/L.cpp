#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    vector<int> L(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        int l = 0, r = i - 3;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pref[mid] < pref[i] - 2 * a[i]) {
                L[i] = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    int mnLen = n + 1;
    vector<ll> ans(n + 1);
    for (int i = n; i >= 1; i--) {
        if (L[i] == -1) continue;

        int len = i - L[i] + 1;
        if (len >= mnLen) {
            continue;
        }
        
        for (int j = len; j < min(i + 1, mnLen); j++) {
            ans[j] = pref[i] - pref[i - j];
        }

        mnLen = len;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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