#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const ll LINF = 9e18;

void solve() {
    int n; cin >> n;
    int N = n + 1;

    vector<int> factors;
    for (ll x = 1; x * x <= N; x++) {
        if (N % x == 0) {
            factors.push_back(x);
            if (x * x != N) {
                factors.push_back(N / x);
            }
        }
    }

    int m = factors.size();

    sort(factors.begin(), factors.end());

    ll A = 1;
    ll ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ll nd = factors[i + 1];
        if (nd <= A) continue;

        ll mns = LINF, place = 0;
        int bestj = -1;
        for (int j = 0; j <= i; j++) {
            ll d = factors[j];
            ll st = A / d * d;
            ll curs = (nd - st + d - 1) / d;
            if (curs < mns) {
                mns = curs;
                bestj = j;
                place = st + mns * d;
            } else if (curs == mns) {
                ll nplace = st + mns * d;
                if (nplace > place) {
                    place = nplace;
                    bestj = j;
                }
            }
        }

        ll d = factors[bestj];

        ans += mns;
        A = A / d * d + mns * d;
    }

    cout << ans << endl;
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