#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'

const double EPS = 1e-6;

int sgn(double x) {
    if (x < EPS) return 0 ;
    if (x <   0) return -1;
    return 1;
}

void solve() {
    double x0, y0, v0, vy;
    double y1, y2, vy1, vy2;
    double x1, x2, vx1, vx2;

    cin >> x0 >> y0 >> v0 >> vy;
    cin >> y1 >> y2 >> vy1 >> vy2;
    cin >> x1 >> x2 >> vx1 >> vx2;

    if (v0 > 0) {
        v0 = -v0;
        x0 = x1 + x2 - x0;
    }

    double T = (y2 - y1) / (vy1 + vy2);
    double now = 0;

    double ansY = y1 + T * vy1;

    {
        if (sgn(-v0 - vx1) <= 0) {
            cout << x0 + v0 * T << " " << ansY << endl;
            return;
        }

        double dT = (x0 - x1) / (-v0 - vx1);

        dT = min(dT, T);

        x1 -= dT * vx1;
        x2 += dT * vx2;
        x0 = x1;

        if (sgn(T - dT) == 0) {
            cout << x0 << " " << ansY << endl;
            return;
        }

        if (sgn(-v0 - vx2) <= 0) {
            double ddT = T - dT;
            cout << x0 + v0 * ddT << " " << ansY << endl;
            return;
        }

        now = dT;
        v0 = -v0;
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

    auto calcD = [&](int n) -> double {
        int nOdd = (n + 1) / 2, nEven = n / 2;
        double tot = D1 * (1 - qpow(q, nOdd )) / (1 - q)
                   + D2 * (1 - qpow(q, nEven)) / (1 - q);
        return tot;
    };

    auto check = [&](int n) -> bool {
        return now + calcD(n) / v0 <= T;
    };

    int upb = 1;
    while (check(upb)) upb <<= 1;

    int l = upb >> 1, r = upb;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    // r

    double usedT = calcD(r) / v0;
    x1 -= vx1 * usedT;
    x2 += vx2 * usedT;

    int nOdd = (r + 1) / 2, nEven = r / 2;

    x0 += D1 * (1 - qpow(q, nOdd )) / (1 - q)
        - D2 * (1 - qpow(q, nEven)) / (1 - q);

    cout << r << endl;
    
    return;

    now += usedT;

    double rem = T - now;
    double go  = rem * v0;
    if (r & 1) x0 -= go;
    else       x0 += go;

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