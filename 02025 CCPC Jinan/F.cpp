#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

bool overlap(int l1, int r1, int l2, int r2) {
    return !(r1 < l2 || l1 > r2);
}

void solve() {
    int n; cin >> n;
    vector<int> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) cin >> L[i];
    for (int i = 1; i <= n; i++) cin >> R[i];

    ll ans = 0;

    vector<pair<int, int>> intv;
    int l = 1;
    while (l <= n) {
        if (R[l] - L[l] + 1 >= 3) {
            ++ans;
            ++l;
            continue;
        }

        int r = l;
        while (
            r < n &&
            R[r + 1] - L[r + 1] + 1 <= 2 && overlap(L[r], R[r], L[r + 1], R[r + 1])
        ) ++r;

        intv.push_back({l, r});
        l = r + 1;
    }

    for (auto &[l, r] : intv) {
        vector<pair<int, int>> nintv;
        
        {
            int i = l;
            while (i <= r) {
                int j = i;
                if (R[i] == L[i]) {
                    while (j <= r && L[j] == R[j] && L[i] == L[j]) {
                        ++j;
                    }
                } else {
                    while (j <= r && R[j] - L[j] + 1 == 2) {
                        ++j;
                    }
                }

                nintv.push_back({i, j - 1});
                i = j;
            }
        }

        vector<int> single;
        for (int i = 0; i < nintv.size(); i++) {
            auto &[p, q] = nintv[i]; 
            if (L[p] == R[p]) {
                ans += (ll)(q - p + 1) * (q - p + 1);
            } else {

                int len = q - p + 1;
                if (i == 0 || i == nintv.size() - 1) { ans += len; continue; }

                if (len == 1 &&
                    ((L[p] == L[p - 1] && R[p] == L[p + 1]) || (L[p] == L[p + 1] && R[p] == L[p - 1]))
                ) {
                    single.push_back(i);
                    continue;
                }

                bool ok = false;

                int prev = L[nintv[i - 1].first];
                for (int j = p; j <= q; j++) {
                    if (prev != L[j] && prev != R[j]) { ok = true; break; }
                    prev = (prev == L[j] ? R[j] : L[j]);
                }

                if (prev == L[q + 1] && !ok) ans += len + 2;
                else ans += len;
            }
        }

        vector<int> cnt(nintv.size());
        for (int i = 0; i < nintv.size(); i++) {
            auto &[p, q] = nintv[i];
            cnt[i] = q - p + 1;
        }

        for (int i = 0; i < single.size(); i++) {
            int j = single[i];
            vector<int> all;

            all.push_back(j - 1);
            all.push_back(j + 1);

            sort(all.begin(), all.end(), [&](const int i, const int j) -> bool {
                return cnt[i] < cnt[j];
            });

            ans += 2 * cnt[all[0]] + 1;
            cnt[all[0]]++;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}