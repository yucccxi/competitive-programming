#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const double PI  = acos(-1);
const double EPS = 1e-6;

struct union_find {
    int components;
    vector<int> parent, sz;

    union_find(int n) {
        sz.resize(n + 1);
        parent.resize(n + 1);
        components = n;

        for (int i = 1; i <= n; i ++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int v) {
        while (parent[v] != v) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }

        return v;
    }

    bool unite(int v, int w) {
        int p = find(v), q = find(w);
        if (p == q) return false;

        if (sz[p] <= sz[q]) {
            swap(p, q);
        }

        parent[q] = p;
        sz[p] += sz[q];

        --components;

        return true;
    }

    int count() { return components; }
};

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

// 迭代形式
void fft(vector<icomplex> &a, int type) {
    int n = a.size();
    if (n == 1) return;

    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int tot = 1;
    while (tot < n + m) {
        tot <<= 1;
    }

    vector<vector<vector<icomplex>>> link(6, 
        vector<vector<icomplex>>(6, 
            vector<icomplex>(tot))
        );

    for (char c0 = 'a'; c0 <= 'f'; c0++) {
        for (char c1 = 'a'; c1 <= 'f'; c1++) {
            if (c0 == c1) continue;

            vector<icomplex> v0(tot), v1(tot);

            int p = c0 - 'a', q = c1 - 'a';
            for (int i = 0; i < n; i++) {
                if (s[i] == c0) v0[i] = icomplex(1, 0);
            }

            for (int i = 0; i < m; i++) {
                if (t[i] == c1) v1[m - 1 - i] = icomplex(1, 0);
            }

            fft(v0, 1);
            fft(v1, 1);

            for (int i = 0; i < tot; i++) {
                link[p][q][i] = v0[i] * v1[i];
            }

            fft(link[p][q], -1);

            for (int i = 0; i < tot; i++) {
                link[p][q][i].r /= tot;
                link[p][q][i].i /= tot;
            }
        }
    }

    for (int i = 0; i < n - m + 1; i++) {
        union_find uf(6);
        for (char c0 = 'a'; c0 <= 'f'; c0++) {
            for (char c1 = 'a'; c1 <= 'f'; c1++) {
                if (c0 == c1) continue;
                int p = c0 - 'a', q = c1 - 'a';
                if (link[p][q][i + m - 1].r > EPS) {
                    uf.unite(p + 1, q + 1);
                }
            }
        }

        cout << 6 - uf.count() << " ";
    }
    cout << endl;
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