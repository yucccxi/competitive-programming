#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    bool same = true;
    for (int i = 1; i <= n - 1; i++) {
    	if (a[i] != a[i + 1]) {
    		same = false;
    		break;
    	}
    }

    if (same) {
    	cout << "infinite" << endl;
    	return;
    }

    ll m = 0;
    for (int i = 1; i <= n - 1; i++) {
    	m = __gcd(m, abs(a[i + 1] - a[i]));
    }

    ll k = m / __gcd(m, a[1]);

    cout << m << " " << k << endl;
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