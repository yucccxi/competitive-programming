// 这题需要一点转换

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct icomplex {
    double r, i;

    icomplex(double real = 0.0, double im = 0.0) : r(real), i(im) {};

    icomplex operator+(const icomplex &o) const {
        return icomplex(r + o.r, i + o.i);
    }

    icomplex operator-(const icomplex &o) const {
        return icomplex(r - o.r, i - o.i);
    }

    icomplex operator*(const icomplex &o) const {
        return icomplex(r * o.r - i * o.i, r * o.i + i * o.r);
    }

    icomplex operator/(const icomplex &o) const {
        double k = o.r * o.r + o.i * o.i;
        return icomplex((r * o.r + i * o.i) / k, (i * o.r - r * o.i) / k);
    }
};

const double PI = acos(-1);

int getid(char c) {
    if (c == 'A') return 0;
    if (c == 'T') return 1;
    if (c == 'C') return 2;
    if (c == 'G') return 3;
    assert(false);
}

void fft(vector<icomplex> &a, int type) {
    int n = a.size();
    if (n == 1) return;

    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? (n >> 1) : 0);
    }

    for (int i = 0; i < n; i++) {
        if (i > rev[i]) swap(a[i], a[rev[i]]);
    }

    for (int l = 1; l < n; l <<= 1) {
        icomplex w0 = icomplex(cos(PI / l), type * sin(PI / l));
        for (int i = 0; i < n; i += (l << 1)) {
            icomplex w = icomplex(1, 0);
            for (int j = i; j < i + l; j++) {
                icomplex u = a[j];
                icomplex v = w * a[j + l];
                a[j]     = u + v;
                a[j + l] = u - v;
                w = w * w0;
            }
        }
    }
}

void solve() {
    int n, m, k;
    int tot = 1;
    cin >> n >> m >> k;
    while (tot < n + m) {
        tot <<= 1;
    }

    string s, t;
    cin >> s >> t;

    vector<bool> ans(n - m + 1, true);

    for (int c = 0; c < 4; c++) {
        vector<icomplex> ch(tot);
        vector<icomplex> f(tot);
        vector<int> pref(n);

        auto get = [&](int l, int r) -> int {
            int vl = (l == 0 ? 0 : pref[l - 1]);
            int vr = pref[r];
            return vr - vl;
        };

        for (int i = 0; i < n; i++) {
            if (i > 0) pref[i] = pref[i - 1];
            pref[i] += (getid(s[i]) == c);
        }

        for (int i = 0; i < m; i++) {
            ch[i].r = (getid(t[m - i - 1]) == c);
        }

        for (int i = 0; i < n; i++) {
            int l = max(0, i - k);
            int r = min(n - 1, i + k);
            f[i].r = (get(l, r) == 0);
        }

        fft(ch, 1);
        fft(f , 1);

        vector<icomplex> vals(tot);

        for (int i = 0; i < tot; i++) {
            vals[i] = ch[i] * f[i];
        }

        fft(vals, -1);

        for (int i = 0; i < tot; i++) {
            vals[i].i /= tot;
            vals[i].r /= tot;
        }

        for (int i = 0; i < n - m + 1; i++) {
            bool ok = llround(vals[i + m - 1].r) == 0;
            ans[i] = ans[i] && ok;
        }
    }

    int match = 0;
    for (int i = 0; i < n - m + 1; i++) {
        match += ans[i];
    }

    cout << match << endl;
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