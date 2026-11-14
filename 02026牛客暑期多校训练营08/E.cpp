#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN  = 5e5 + 5;
const int MAXLG = 21;

int n, m;
string s, t;

int sa[MAXN], rk[MAXN], height[MAXN];
int id[MAXN], cnt[MAXN], oldrk[MAXN], p;

void build_suffix_array() {
    int m = 128;

    for (int i = 1; i <= n; i++) {
        rk[i] = s[i];
    }

    for (int i = 1; i <= n; i++) {
        cnt[rk[i]]++;
    }

    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        sa[cnt[rk[i]]--] = i;
    }

    for (int w = 1;; w <<= 1) {
        int p = 0;

        for (int i = n - w + 1; i <= n; i++) {
            id[++p] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (sa[i] > w) {
                id[++p] = sa[i] - w;
            }
        }

        fill(cnt, cnt + m + 1, 0);

        for (int i = 1; i <= n; i++) {
            cnt[rk[i]]++;
        }

        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }

        for (int i = n; i >= 1; i--) {
            int x = id[i];
            int key = rk[x];

            sa[cnt[key]--] = x;
        }

        for (int i = 1; i <= n; i++) {
            oldrk[i] = rk[i];
        }

        rk[sa[1]] = 1;

        for (int i = 2; i <= n; i++) {
            int x = sa[i - 1];
            int y = sa[i];

            int x1 = oldrk[x];
            int y1 = oldrk[y];

            int x2 = (x + w <= n ? oldrk[x + w] : 0);
            int y2 = (y + w <= n ? oldrk[y + w] : 0);

            bool diff = (x1 != y1 || x2 != y2);

            rk[y] = rk[x] + diff;
        }

        m = rk[sa[n]];

        if (m == n) break;
    }
}

void build_height() {
    int h = 0;
    for (int i = 1; i <= n; i++) {
        int r = rk[i];
        if (r == 1) { height[r] = 0; continue; }
        int j = sa[r - 1];

        while (i + h <= n && j + h <= n && s[i + h] == s[j + h]) {
            h++;
        }

        height[r] = h;

        if (h > 0) --h;
    }
}

struct node {
    int depth;
    int pos;
    int parent;
    vector<int> children;

    node(int _depth, int _pos, int _parent) : depth(_depth), pos(_pos), parent(_parent) {}
};

int nodes = 0;
vector<node> suftree;

int create_node(int depth, int pos, int parent) {
    int c = nodes++;
    suftree.emplace_back(depth, pos, parent);
    return c;
}

void solve() {
    cin >> s >> t;
    n = s.size() + 1, m = t.size();
    s = '.' + s, t = '.' + t;
    s += '$';

    build_suffix_array();
    build_height();

    create_node(0, -1, -1);
    stack<int> stk;
    stk.push(0);

    for (int i = 1; i <= n; i++) {
        while (suftree[stk.top()].depth > height[i]) {
            stk.pop();
        }


        if (suftree[p].depth < height[i]) {
            assert(stk.size() > 0);
            int p = stk.top();

            assert(suftree[p].children.size() > 0);
            int sid = suftree[p].children.back();
            suftree[p].children.pop_back();

            int nid = create_node(height[i], suftree[sid].pos, p);
            suftree[p].children.push_back(nid);
            suftree[nid].children.push_back(sid);
            suftree[sid].parent = nid;

            stk.push(nid);
        }

        int p = stk.top();

        int lid = create_node(n - sa[i] + 1, sa[i], p);
        suftree[p].children.push_back(lid);
    }


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