#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int INF = 1e9;

struct point {
    int x, y, z;
    int yrank;
    int pos;
};

struct fenwick2d {

    int n;
    vector<vector<int>> tree;
    vector<vector<int>> zs;

    int lowbit(int x) { return x & -x; }

    fenwick2d(int _n, vector<point> &pts) : n(_n) {
        zs.resize(n + 1);
        tree.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            for (int j = pts[i].yrank; j <= n; j += lowbit(j)) {
                zs[j].push_back(pts[i].z);
            }
        }

        for (int i = 1; i <= n; i++) {
            sort(zs[i].begin(), zs[i].end());
            zs[i].erase(unique(zs[i].begin(), zs[i].end()), zs[i].end());
        }

        for (int i = 1; i <= n; i++) {
            tree[i].resize(zs[i].size() + 1, INF);
        }
    }

    void update(int y, int z, int val) {
        for (int i = y; i <= n; i += lowbit(i)) {
            int pos = lower_bound(zs[i].begin(), zs[i].end(), z) - zs[i].begin() + 1;
            for (int j = pos; j <= zs[i].size(); j += lowbit(j)) {
                tree[i][j] = min(tree[i][j], val);
            }
        }   
    }

    int query(int y, int z) {
        int ans = INF;
        if (y <= 1) return ans;
        for (int i = y - 1; i > 0; i -= lowbit(i)) {
            int pos = lower_bound(zs[i].begin(), zs[i].end(), z) - zs[i].begin() + 1;
            if (pos <= 1) continue;
            for (int j = pos - 1; j > 0; j -= lowbit(j)) {
                ans = min(ans, tree[i][j]);
            }
        }
        return ans;
    }
};

int solvei(int n, vector<int> &a, int k) {
    vector<vector<int>> pre(4, vector<int>(n + 1));
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] += pre[i][j - 1];
            pre[i][j] += (a[j] == i);
        }
    }


    vector<point> pts(n + 1);
    vector<int> ys;
    for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j = 0; j < 4; j++) {
            if (j == k) continue;
            v.push_back(pre[k][i] - pre[j][i]);
        }

        pts[i].x = v[0];
        pts[i].y = v[1];
        pts[i].z = v[2];
        pts[i].pos = i;

        ys.push_back(v[1]);
    }

    ys.push_back(0);

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    for (int i = 0; i <= n; i++) {
        pts[i].yrank = lower_bound(ys.begin(), ys.end(), pts[i].y) - ys.begin() + 1;
    }

    fenwick2d fw(n, pts);

    sort(pts.begin(), pts.end(), [&](const point &p1, const point &p2) -> bool {
        return p1.x < p2.x;
    });

    int ans = 0;
    int l = 0;
    while (l <= n) {
        int r = l;
        while (r <= n && pts[r].x == pts[l].x) {
            r++;
        }

        for (int i = l; i < r; i++) {
            int j = fw.query(pts[i].yrank, pts[i].z);
            ans = max(ans, pts[i].pos - j);
        } 

        for (int i = l; i < r; i++) {
            fw.update(pts[i].yrank, pts[i].z, pts[i].pos);
        }

        l = r;
    }

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }


    for (int i = 0; i < 4; i++) {
        cout << solvei(n, a, i) << " ";
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