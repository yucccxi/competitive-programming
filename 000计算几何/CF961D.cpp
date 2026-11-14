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

using PointD   = Point<double>     ;
using PointLD  = Point<long double>;
using PointLL  = Point<ll>         ; 

const int MAXN = 1e5 + 5;

int n;
PointLL pts[MAXN];

bool onLine(const PointLL &p, const PointLL &q, const PointLL &t) {
    return (t.x - p.x) * (t.y - q.y) == (t.x - q.x) * (t.y - p.y);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        pts[i] = PointLL(x, y);
    }

    if (n <= 2) {
        cout << "YES" << endl;
        return;
    }

    int pos;
    for (pos = 3; pos <= n; pos++) {
        if (!onLine(pts[1], pts[2], pts[pos])) {
            break;
        }
    }

    if (pos == n + 1) {
        cout << "YES" << endl;
        return;
    }

    PointLL u[3] = {pts[1], pts[2], pts[pos]};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int a = -1, b = -1;
            bool ok = true;

            for (int l = 1; l <= n; l++) {
                if (onLine(u[i], u[j], pts[l])) continue;

                if (a == -1) {
                    a = l;
                } else if (b == -1) {
                    b = l;
                } else if (!onLine(pts[a], pts[b], pts[l])) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
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