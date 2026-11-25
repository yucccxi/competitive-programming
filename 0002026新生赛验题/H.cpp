#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct Schema {

    struct Food {
        int weight;
        int count;
        bool operator<(const Food &o) const { return weight < other.weight; }
        bool operator>(const Food &o) const { return weight > other.weight; }
    };

    int n;
    vector<Food> tot;
    vector<int> schema;

    Schema(vector<Food> _tot) : tot(_tot) {
        n = tot.size();
        sort(tot.begin(), tot.end());
        schema.resize(n);
    }
};

void solve() {
    
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