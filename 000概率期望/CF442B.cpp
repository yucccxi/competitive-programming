#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 105;

const double EPS = 1e-10;

int n;
double a[MAXN];

double u = 1, v = 0;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 正确性可以由交换证明得到
    sort(a + 1, a + 1 + n, greater<double>());

    for (int i = 1; i <= n; i++) {
        if (1 - a[i] < EPS) {
            cout << 1.0 << endl;
            return;
        }
    }

    for (int i = 1; i <= n && v < 1; i++) {
        u *= 1 - a[i];
        v += a[i] / (1 - a[i]);
    }

    cout << u * v << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}