#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int S, F[8];

bool check(int X) {
    int R1 = max(0, X - F[1]);
    int R2 = max(0, X - F[2]);
    int R3 = max(0, X - F[4]);

    if (F[3] + F[5] + F[7] < R1) return false;
    if (F[3] + F[6] + F[7] < R2) return false;
    if (F[5] + F[6] + F[7] < R3) return false;
    if (F[3] + F[5] + F[6] + F[7] < R1 + R2 + R3) return false;
    return true;
}

void solve() {
    cin >> S;
    for (int i = 1; i <= 7; i++) {
        cin >> F[i];
    }

    int l = 0, r = S;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    cout << r << endl;
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