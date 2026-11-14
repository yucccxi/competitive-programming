#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
    int n; cin >> n;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    string s; cin >> s;
    s = "." + s; 

    ll inv = 0, c0 = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) c0++;
        else           inv += c0;
    }

    vector<ll> u(1), v(1); 
    ll U = 0, V = 0;
    
    int i = 1;
    while (i <= n && a[i] == 0) i++;
    
    while (i <= n) {
        ll cu = 0, cv = 0;
        while (i <= n && a[i] == 1) cu++, i++;
        while (i <= n && a[i] == 0) cv++, i++;
        if (cu > 0 && cv > 0) {
            u.push_back(cu);
            v.push_back(cv);
            U += cu;
            V += cv;
        }
    }

    cout << inv << " ";
    int l = 1, r = u.size() - 1;

    for (int k = 1; k <= n; k++) {
        if (l > r) {
            cout << 0 << " ";
            continue;
        }

        if (s[k] == '1') {
            inv -= V;
            u[l]--;
            U--;
            if (u[l] == 0) {
                V -= v[l];
                l++;
            }
        } else {
            inv -= U;
            v[r]--;
            V--;
            if (v[r] == 0) {
                U -= u[r];
                r--;
            }
        }

        cout << max(0LL, inv) << " ";
    }
    cout << endl;
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