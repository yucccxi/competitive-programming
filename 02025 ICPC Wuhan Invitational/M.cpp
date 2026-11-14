#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr double EPS = 1e-9;

int r;

tuple<double, double, double> mapper(double a, double b, double c) {
    double x, y, z;
    x = r * a / sqrt(a * a + b * b + c * c);
    y = r * b / sqrt(a * a + b * b + c * c);
    z = r * c / sqrt(a * a + b * b + c * c);
    return {x, y, z};
}

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
    double d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
    return r * acos(1 - d2 / (2 * r * r));
}

void solve() {
    cin >> r;
    int a, b, c;
    cin >> a >> b >> c;
    auto [x, y, z] = mapper(a, b, c);
    cin >> a >> b >> c;
    auto [sx, sy, sz] = mapper(a, b, c);
    cin >> a >> b >> c;
    auto [ex, ey, ez] = mapper(a, b, c);

    double lx = sx, ly = sy, lz = sz;
    double rx = ex, ry = ey, rz = ez;
    while (abs(rx - lx) > EPS || abs(ry - ly) > EPS || abs(rz - lz) > EPS) {
        double dx = (rx - lx) / 3;
        double dy = (ry - ly) / 3;
        double dz = (rz - lz) / 3;
        auto [mlx, mly, mlz] = mapper(lx + dx, ly + dy, lz + dz);
        auto [mrx, mry, mrz] = mapper(lx + 2 * dx, ly + 2 * dy, lz + 2 * dz);
        double distl = dist(x, y, z, mlx, mly, mlz);
        double distr = dist(x, y, z, mrx, mry, mrz);
        if (distl > distr) {
            lx = mlx, ly = mly, lz = mlz;
        } else {
            rx = mrx, ry = mry, rz = mrz;
        }
    }

    cout << dist(x, y, z, lx, ly, lz) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed << setprecision(9);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}