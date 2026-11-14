#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

template<typename T>
struct Point {

    T x, y;

    Point() {}
    Point(T _x, T _y) : x(_x), y(_y) {}
    
    Point operator+(const Point &o) const {
        return Point(x + o.x, y + o.y);
    }

    Point operator-(const Point &o) const {
        return Point(x - o.x, y - o.y);
    }

    Point operator/(const T val) const {
        return Point(x / val, y / val);
    }

    Point operator*(const T val) const {
        return Point(x * val, y * val);
    }

    static T dot(const Point &a, const Point &b) {
        return a.x * b.x + a.y * b.y;
    }

    static T cross(const Point &a, const Point &b) {
        return a.x * b.y - a.y * b.x;
    }

    static T dist2(const Point &vec) {
        return (vec.x * vec.x + vec.y * vec.y);
    }

    static double dist(const Point &vec) {
        return sqrt(dist2(vec));
    }
};

using PointD = Point<double>;

const int MAXN = 1e5 + 5;
const double PI = acos(-1);

int n;
PointD pts[MAXN], p;

void solve() {
    cin >> n >> p.x >> p.y;
    
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        pts[i] = PointD(x, y);
    }

    double lo = 9e18, hi = 0;

    for (int i = 1; i <= n; i++) {
        hi = max(hi, PointD::dist2(p - pts[i]));

        PointD L = pts[i], R = pts[i % n + 1];
        for (int j = 0; j < 64; j++) {
            PointD dP = (R - L) / 3;
            PointD mL = L + dP, mR = R - dP;
            
            if (PointD::dist2(mL - p) < PointD::dist2(mR - p)) {
                R = mR;
            } else {
                L = mL;
            }
        }

        lo = min(lo, PointD::dist2(p - (L + R) / 2));
    }

    cout << PI * (hi - lo) << endl;
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