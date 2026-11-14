#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr int INF = 1e9;
constexpr int MAXN = 105;

int n, m;
string all[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> all[i];
    }
    
    int ans = 0;
    
    for (int j = 0; j < m; j++) {
        int cnt[26] = {};
        for (int i = 0; i < n; i++) {
            cnt[all[i][j] - 'a']++;
        }
        
        int mx = 0;
        
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > cnt[mx]) {
                mx = i;
            }
        }
        
        for (int i = 0; i < n; i++) {
            ans += all[i][j] - 'a' != mx;
        }
    }
    
    cout << ans << endl;
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
