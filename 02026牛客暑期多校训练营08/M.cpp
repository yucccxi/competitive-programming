#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const int MAXN = 1e6 + 5;

int n, m;
vector<string> all;

int trie[MAXN][26], ptr[MAXN], parent[MAXN], id;
vector<int> seen[MAXN];

bool marked[MAXN];

// {next_time, id}
priority_queue<pair<int, int>> pq;
int cached, tot;

void insert(const string &s, int t) {
    int cur = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[cur][c] == 0) {
            trie[cur][c] = ++id;
            parent[id] = cur;
        }

        cur = trie[cur][c];
        seen[cur].push_back(t);
    }
}

void cache(int t) {
    int cur = 0;
    for (char ch : all[t]) {
        int c = ch - 'a';
        cur = trie[cur][c];
        if (!marked[cur]) {
            marked[cur] = true;
            cached++;
            tot++;
        }
    }

    while (seen[cur][ptr[cur]] <= t) {
        ptr[cur]++;
    }

    pq.push({seen[cur][ptr[cur]], cur});
}

void check_and_erase(int t) {
    while (cached > m) {
        auto [next_time, id] = pq.top();
        pq.pop();
        
        if (!marked[id]) continue;
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (marked[trie[id][i]]) {
                ok = false;
                break;
            }
        }

        if (!ok) continue;

        cached--;
        marked[id] = false;
        int p = parent[id];
        if (p > 0) {
            while (seen[p][ptr[p]] <= t) {
                ptr[p]++;
            }
            pq.push({seen[p][ptr[p]], p});
        }
    }
}

void solve() {
    cin >> n >> m;
    all.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> all[i];
        insert(all[i], i);
    }

    for (int i = 1; i <= id; i++) {
        seen[i].push_back(n + 1);
    }

    for (int i = 0; i < n; i++) {
        cache(i);
        check_and_erase(i);
    }

    cout << tot << endl;
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