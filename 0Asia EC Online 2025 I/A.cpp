#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

struct submission {
    int pid;
    int time;
    string verd;

    bool operator<(const submission &o) const {
        if (pid != o.pid) return pid < o.pid;
        return time < o.time;
    }
};

struct team {
    string name;
    int count;
    int penalty;

    bool operator<(const team &o) const {
        if (count != o.count) return count < o.count;
        if (penalty != o.penalty) return penalty > o.penalty;
        return name < o.name;
    }
};

void solve() {
    int n; cin >> n;
    map<string, vector<submission>> subs;
    for (int i = 1; i <= n; i++) {
        string tname, verd;
        char pid;
        int time;
        cin >> tname >> pid >> time >> verd;
        subs[tname].push_back({pid - 'a', time, verd});
    }

    for (auto &[k, v] : subs) {
        sort(v.begin(), v.end());
    }
    
    map<string, pair<int, int>> penalty;
    map<string, map<int, int>> accumulation;
    map<string, vector<submission>> first_unknown;
    for (auto &[k, v] : subs) {
        int ac = 0;
        penalty[k] = {};
        for (submission &sub : v) {
            int pid = sub.pid;

            if (ac >> pid & 1) continue;

            if (sub.verd == "Rejected") {
                accumulation[k][pid] += 20;
            }

            if (sub.verd == "Accepted") {
                penalty[k].second += accumulation[k][pid] + sub.time;
                penalty[k].first++;
                ac |= (1 << pid);
            }

            if (sub.verd == "Unknown") {
                first_unknown[k].push_back(sub);
                ac |= (1 << pid);
            }
        }
    }

    vector<team> teams;
    for (auto &[k, v] : penalty) {
        teams.push_back({k, v.first, v.second});
    }

    sort(teams.begin(), teams.end());

    vector<string> ans;

    for (int i = 0; i < teams.size(); i++) {
        team cur = teams[i];
        for (auto sub : first_unknown[cur.name]) {
            cur.penalty += accumulation[cur.name][sub.pid];
            cur.penalty += sub.time;
            cur.count++;
        }

        if (cur.count > teams.back().count || 
            (cur.count == teams.back().count && cur.penalty <= teams.back().penalty)
        ) {
            ans.push_back(cur.name);
        }
    }

    sort(ans.begin(), ans.end());

    for (string &s : ans) {
        cout << s << " ";
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