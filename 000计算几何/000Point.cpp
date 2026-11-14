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

const double PI = acos(-1);

void solve() {
    
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