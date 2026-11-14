#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct Point {

    ll x, y;

    Point() {}

    Point(ll _x, ll _y) : x(_x), y(_y) {}
    
    Point operator+(const Point &o) const {
        return Point(x + o.x, y + o.y);
    }

    Point operator-(const Point &o) const {
        return Point(x - o.x, y - o.y);
    }
};

ll dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

ll cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double dist(const Point &vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

void solve() {
    int n; cin >> n;
    vector<Point> pts(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = Point(x, y);
    }

    double ans = 9e18;

    for (int i = 1; i <= n; i++) {
        int j = i % n + 1;
        int k = j % n + 1;

        ll S = abs(cross(pts[j] - pts[i], pts[k] - pts[i]));
        double D = 2 * max({dist(pts[i] - pts[j]), dist(pts[i] - pts[k]), dist(pts[j] - pts[k])});

        ans = min(ans, S / D);
    }

    cout << ans << endl;
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