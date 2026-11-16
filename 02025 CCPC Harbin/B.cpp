#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'

const double EPS = 1e-6;

int sgn(double x) {
    if (abs(x) < EPS) return 0 ;
    if (x < 0) return -1;
    return 1;
}

void solve() {
    double x0, y0, v0, vy;
    double y1, y2, vy1, vy2;
    double x1, x2, vx1, vx2;

    cin >> x0 >> y0 >> v0 >> vy;
    cin >> y1 >> y2 >> vy1 >> vy2;
    cin >> x1 >> x2 >> vx1 >> vx2;

    double T = (y2 - y1) / (vy1 + vy2);
    double now = 0;

    double ansY = y1 + T * vy1;

    if (v0 > 0) {
        if (sgn(vx2 - v0) >= 0) {
            cout << x0 + v0 * T << " " << ansY << endl;
            return;
        }

        double dT = (x2 - x0) / (v0 - vx2);
        if (dT >= T) {
            cout << x0 + v0 * T << " " << ansY << endl;
            return;
        }

        now += dT;
        x1 -= vx1 * dT;
        x2 += vx2 * dT;
        x0 += v0 * dT;

        v0 = -v0;
    }

    if (v0 < 0) {
        if (sgn(vx1 + v0) >= 0) {
            cout << x0 + v0 * (T - now) << " " << ansY << endl;
            return;
        }

        double dT = (x0 - x1) / (-v0 - vx1);
        if (dT >= T - now) {
            cout << x0 + v0 * (T - now) << " " << ansY << endl;
            return;
        }

        now += dT;
        x1 -= vx1 * dT;
        x2 += vx2 * dT;
        x0 += v0 * dT;

        v0 = -v0;
    }

    if (v0 <= vx2) {
        cout << x0 + v0 * (T - now) << " " << ansY << endl;
        return;
    }

    auto qpow = [&](double v, int n) -> double {
        double ret = 1;
        while (n > 0) {
            if (n & 1) {
                ret *= v;
            }

            v *= v;
            n >>= 1;
        }

        return ret;
    };

    double D0 = x2 - x1;
    double D1 = (v0 + vx1) / (v0 - vx2) * D0;
    double D2 = (v0 + vx2) / (v0 - vx1) * D1;

    double q  = (v0 + vx1) * (v0 + vx2) / (v0 - vx1) / (v0 - vx2);

    auto geom = [&](int k) -> double {
        if (k == 0) return 0.0;
        if (sgn(q - 1.0) == 0) return k;
        return (qpow(q, k) - 1.0) / (q - 1.0);
    };

    auto calcOdd = [&](int n) -> double {
        return v0 / (v0 - vx2) * D0 * geom((n + 1) / 2);
    };

    auto calcEven = [&](int n) -> double {
        return v0 / (v0 - vx1) * D1 * geom(n / 2);
    };

    auto calcS = [&](int n) -> double {
        return calcOdd(n) + calcEven(n);
    };

    auto check = [&](int n) -> bool {
        return now + calcS(n) / v0 <= T;
    };

    int upb = 1;
    while (check(upb)) upb <<= 1;

    int l = 0, r = upb;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    // r;

    double usedT = calcS(r) / v0;
    x1 -= vx1 * usedT;
    x2 += vx2 * usedT;

    x0 += calcOdd(r) - calcEven(r);
    
    now += usedT;

    double remain = T - now;
    if (r & 1) {
        x0 -= abs(v0) * remain;
    } else {
        x0 += abs(v0) * remain;
    }

    cout << x0 << " " << ansY << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ B_.cpp -O2 -o out && ./out < in.txt