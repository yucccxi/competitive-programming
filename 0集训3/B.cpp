#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int r;
int xq, yq, l;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double arcl(double h1, double h2) {
    double ans = 0;
    ans += asin(+h1 / r) * r;
    ans += asin(-h2 / r) * r;
    return ans;
}

void solve() {
    cin >> r;
    cin >> xq >> yq >> l;
    
    double h = dist(0, 0, xq, yq);
    cout << fixed << setprecision(9) << arcl(h + l, h - l) << endl;
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