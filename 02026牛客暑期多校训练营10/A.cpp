#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const double EPS = 1e-8;

struct point {
    
    ll x, y;

    point() {}

    point(ll _x, ll _y) : x(_x), y(_y) {}

    ll cross(const point &o) {
        return x * o.y - o.x * y;
    }

    ll dot(const point &o) {
        return x * o.x + y * o.y;
    }

    double dist_to(const point &o) {
        return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
    }
};

ll sx, sy, ax, ay, bx, by;
double r;

point zero, sun, a, b;

int sgn(double x) {
    if (abs(x) < EPS) return 0;
    return x < 0 ? -1 : +1;
}

double calculate(double x, double y) {
    return (double)sx / sy * (-y) + x;
}

void solve() {
    cin >> sx >> sy >> ax >> ay >> bx >> by;

    zero = point(0, 0);
    sun  = point(sx, sy);
    a    = point(ax, ay);
    b    = point(bx, by);

    r = zero.dist_to(a);

    double iy = r * sy / zero.dist_to(sun);
    double ix = sgn(sx) * sqrt(r * r - iy * iy);
    double ty = abs(ix);
    double tx = -sgn(sx) * iy;

    double ans = 0;
    
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