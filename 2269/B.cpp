#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int val[1001];

int compute(int v) {
    int ans = 0;
    while (v > 0) {
        int d = v % 10;
        v /= 10;
        ans += d * d;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = compute(a[i]);
        a[i] = val[a[i]];
    }

    map<int, int> freq;

    for (int i = 1; i <= n; i++) {
        freq[a[i]]++;
    }

    ll ans = 0;
    for (auto &[k, v] : freq) {
        ans += ((ll)v * (v - 1)) / 2;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 1000; i++) {
        int v = i;
        for (int j = 0; j < 100; j++) {
            v = compute(v);
        }
        val[i] = v;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}