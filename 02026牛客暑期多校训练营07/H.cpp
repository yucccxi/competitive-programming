#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

vector<int> langford(int n) {
    if (n % 4 == 1 || n % 4 == 2) {
        return {};
    }

    vector<int> ans(2 * n + 1);

    int m = (n + 1) / 4;
    for (int i = 1; i <= 2 * m + 3; i += 2) {
        ans[2 * m - (i + 1) / 2] = i;
        ans[2 * m + (i + 1) / 2] = i;
    }

    for (int i = 2; i <= 2 * m - 2; i += 2) {
        ans[6 * m - 1 - i / 2] = i;
        ans[6 * m + i / 2] = i;
    }

    for (int i = 2 * m + 1; i <= 4 * m - 3; i += 2) {
        ans[6 * m - 1 - (i + 1) / 2] = i;
        ans[6 * m - 1 + (i + 1) / 2] = i;
    }

    for (int i = 2 * m; i <= 4 * m - 4; i += 2) {
        ans[2 * m - 1 - i / 2] = i;
        ans[2 * m + i / 2] = i;
    }

    if (n % 4 == 0) {
        ans[m] = 4 * m - 2;
        ans[5 * m - 1] = 4 * m - 2;
        ans[2 * m] = 4 * m - 1;
        ans[6 * m] = 4 * m - 1;
        ans[6 * m - 1] = 2 * m - 1;
        ans[8 * m - 1] = 2 * m - 1;
        ans[4 * m - 1] = 4 * m;
        ans[8 * m] = 4 * m;
    } else {
        ans[m] = 4 * m - 2;
        ans[5 * m - 1] = 4 * m - 2;
        ans[2 * m] = 4 * m - 1;
        ans[6 * m] = 4 * m - 1;
        ans[4 * m - 1] = 2 * m - 1;
        ans[6 * m - 1] = 2 * m - 1;
    }

    return ans;
}

void test() {
    int n = 7;
    vector<int> l = langford(n);
    for (int i = 1; i <= 2 * n; i++) {
        cout << l[i] << " ";
    }
    cout << endl;
}

void solve() {
    int n; cin >> n;
    if (n % 2 == 0) {
        
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}