#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'

const int MAXN = 3e5 + 15;
const int SQ   = 1000; 

int dist[MAXN / SQ + 5][MAXN];
int lastans = 0;
vector<int> digits[MAXN];

int curdist[MAXN];
vector<int> modified;

int q[MAXN];

void solve() {
    int x, y;
    cin >> x >> y;

    x ^= lastans + 1;
    y ^= lastans + 1;

    if (x == 0 && y > 0) {
        lastans = -1;
        cout << -1 << endl;
        return;
    }

    if (x == y) {
        lastans = 0;
        cout << 0 << endl;
        return;
    }

    if (abs(x - y) <= SQ) {
        int low = max(0, min(x, y) - 50);
        int high = min(MAXN - 1, max(x, y) + 50);

        int head = 0, tail = 0;
        q[tail++] = x;
        curdist[x] = 0;
        modified.push_back(x);
        
        bool found = false;
        while (head < tail) {
            int ft = q[head++];
            if (ft == y) {
                found = true;
                break;
            }

            for (int d : digits[ft]) {
                int u = ft + d, v = ft - d;
                
                if (u <= high && u != x && curdist[u] == 0) {
                    curdist[u] = curdist[ft] + 1;
                    q[tail++] = u;
                    modified.push_back(u);
                }

                if (v >= low && v != x && curdist[v] == 0) {
                    curdist[v] = curdist[ft] + 1;
                    q[tail++] = v;
                    modified.push_back(v);
                }
            }
        }

        if (x != y && curdist[y] == 0) {
            lastans = -1;
        } else {
            lastans = curdist[y];
        }
        cout << lastans << endl;

        for (int i : modified) {
            curdist[i] = 0;
        }
        modified.clear();
    } else {
        int current = (x + SQ / 2) / SQ * SQ;
        if (current >= MAXN) current = (MAXN - 1) / SQ * SQ;
        
        int low = max(0, min(x, current) - 50);
        int high = min(MAXN - 1, max(x, current) + 50);
        
        int head = 0, tail = 0;
        q[tail++] = x;
        curdist[x] = 0;
        modified.push_back(x);
        
        while (head < tail) {
            int ft = q[head++];
            if (ft == current) break;
            
            for (int d : digits[ft]) {
                int u = ft + d, v = ft - d;
                if (u <= high && u != x && curdist[u] == 0) {
                    curdist[u] = curdist[ft] + 1;
                    q[tail++] = u;
                    modified.push_back(u);
                }
                if (v >= low && v != x && curdist[v] == 0) {
                    curdist[v] = curdist[ft] + 1;
                    q[tail++] = v;
                    modified.push_back(v);
                }
            }
        }
        
        int ans = -1;
        if (current == x || curdist[current] > 0 || current == y) {
            int to_shard = curdist[current];
            int pos = current / SQ;

            if (dist[pos][y] > 0 || y == current) {
                ans = to_shard + dist[pos][y];
            }
        }
        
        lastans = ans;
        cout << lastans << endl;

        for (int i : modified) {
            curdist[i] = 0;
        }
        modified.clear();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i < MAXN; i++) {
        int t = i;
        while (t > 0) {
            digits[i].push_back(t % 10);
            t /= 10;
        }
        sort(digits[i].begin(), digits[i].end());
        digits[i].erase(unique(digits[i].begin(), digits[i].end()), digits[i].end());
    }

    for (int i = SQ; i < MAXN; i += SQ) {
        int pos = i / SQ;

        int head = 0, tail = 0;
        q[tail++] = i;
        
        while (head < tail) {
            int ft = q[head++];

            for (int d : digits[ft]) {
                int u = ft + d;
                if (u < MAXN && u != i && dist[pos][u] == 0) {
                    dist[pos][u] = dist[pos][ft] + 1;
                    q[tail++] = u;
                }

                int v = ft - d;
                if (v >= 0 && v != i && dist[pos][v] == 0) {
                    dist[pos][v] = dist[pos][ft] + 1;
                    q[tail++] = v;
                }
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}