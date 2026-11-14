#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    int xra = 0, xrb = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xra ^= a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        xrb ^= b[i];
    }

    vector<int> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++) {
        A[i] = xra ^ a[i];
        B[i] = xrb ^ b[i];
    }

    A[0] = xra, B[0] = xrb;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (A == B) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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