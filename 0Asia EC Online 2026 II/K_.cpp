#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    map<int,int> cnt;

    for (int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<int> idx;
    for (int i=0;i<=n;i++){
        if (!cnt.count(i)){
            idx.push_back(i);
        }
    }

    int q;
    cin >> q;
    int xr = 0;

    map<int,int> memo;
    while (q--){
        int k;
        cin >> k;
        if (memo.count(k)){
            xr^=memo[k];
            continue;
        }

        int res = 0;
        int lim = n;
        for (auto& i:idx){
            res = i;
            if (i>=lim) break;
            if (i>k) break;

            if (k%2==0 && i==k/2){
                break;
            }

            int c = cnt[k - i];

            if (i<=k/2){
                if (!c){
                    break;
                }
                else if (c==1){
                    lim = min(lim,k-i);
                }
            }
            else{
                if (!c || c==1){
                    break;
                }
            }

            res = i+1;
        }

        res = min(res,lim);
        memo[k] = res;
        // cout << res << '\n';
        xr^=res;
    }

    cout << xr << '\n';
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

// g++ template.cpp -o out.exe && .\out.exe < in.txt