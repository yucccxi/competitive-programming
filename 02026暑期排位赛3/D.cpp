#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 3e5 + 5;

mt19937 rng(random_device{}());

struct Q {
    int l, r;
};

int n, m, sq;
int a[MAXN];

int freq[MAXN], totdiff;

int pre[MAXN], mo[MAXN], diff, l = 1, r = 0;
vector<Q> all;

ll ans;

void solve() {
    cin >> n >> m;
    sq = 3 * sqrt(n) + 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (freq[a[i]]++ == 0) {
            ++totdiff;
        }
    }

    for (int i = 1; i <= n; i++) {
        all.push_back({pre[a[i]], i});
        pre[a[i]] = i;
    }

    sort(all.begin(), all.end(), [&](const Q &q1, const Q &q2) -> bool {
        int b1 = q1.l / sq;
        int b2 = q2.l / sq;
        if (b1 != b2) return b1 < b2;
        int b = (b1 & 1) ? -1 : +1;
        return q1.r * b < q2.r * b;
    });

    ans = (ll)m * (m - 1) / 2 - (ll)(m - totdiff) * (m - totdiff - 1) / 2;

    auto swift = [&](int tl, int tr) -> void {
        while (l < tl) {
            if (--mo[a[l]] == 0) {
                diff--;
            }
            l++;
        }

        while (r > tr) {
            if (--mo[a[r]] == 0) {
                diff--;
            }
            r--;
        }

        while (l > tl) {
            l--;
            if (mo[a[l]]++ == 0) {
                diff++;
            }
        }

        while (r < tr) {
            r++;
            if (mo[a[r]]++ == 0) {
                diff++;
            }
        }
    };

    for (Q &q : all) {
        swift(q.l + 1, q.r);
        ans += diff - 1;
    }

    cout << ans << endl;
}

void generate() {
    int n = 300000;
    int m = rng() % n + 1;
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        cout << rng() % m + 1 << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // generate();

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}