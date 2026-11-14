#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 3e5 + 5;

int n;
int a[MAXN], cnt[30][4];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        for (int j = 0; j < 30; j++) {
            if (j == 29) continue;
            int lo = x >> j & 0b11;
            cnt[j][lo]++;
        }
    }

    auto flip0 = [&](int i) -> void {
        if (i != 0) {
            cnt[i - 1][0b10] += cnt[i - 1][0b00];
            cnt[i - 1][0b11] += cnt[i - 1][0b01];
            cnt[i - 1][0b01] = 0;
            cnt[i - 1][0b00] = 0;
        }

        if (i != 29) {
            cnt[i][0b01] += cnt[i][0b00];
            cnt[i][0b11] += cnt[i][0b10];
            cnt[i][0b00] = 0;
            cnt[i][0b10] = 0;
        }
    };

    auto flip1 = [&](int i) -> void {
        if (i != 0) {
            cnt[i - 1][0b01] += cnt[i - 1][0b11];
            cnt[i - 1][0b00] += cnt[i - 1][0b10];
            cnt[i - 1][0b11] = 0;
            cnt[i - 1][0b10] = 0;
        }

        if (i != 29) {
            cnt[i][0b00] += cnt[i][0b01];
            cnt[i][0b10] += cnt[i][0b11];
            cnt[i][0b01] = 0;
            cnt[i][0b11] = 0;
        }
    };

    auto flip = [&](int i) -> void {
        if (i != 0) {
            swap(cnt[i - 1][0b01], cnt[i - 1][0b11]);
            swap(cnt[i - 1][0b00], cnt[i - 1][0b10]);
        }

        if (i != 29) {
            swap(cnt[i][0b00], cnt[i][0b01]);
            swap(cnt[i][0b10], cnt[i][0b11]);
        }
    };

    int m; cin >> m;
    while (m--) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            for (int i = 0; i < 30; i++) {
                if (x >> i & 1) continue;
                flip1(i);
            }
        } else if (type == 2) {
            for (int i = 0; i < 30; i++) {
                if (x >> i & 1 ^ 1) continue;
                flip0(i);
            }
        } else if (type == 3) {
            for (int i = 0; i < 30; i++) {
                if (x >> i & 1) flip(i);
            }
        }

        int cnt1 = 0, cnt11 = 0;

        for (int i = 0; i < 30; i += 2) {
            cnt1 += cnt[i][0b10] + cnt[i][0b01] + cnt[i][0b11] * 2;
            cnt11 += cnt[i][0b11] + cnt[i + 1][0b11];
        }

        cout << cnt1 - cnt11 << endl;
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