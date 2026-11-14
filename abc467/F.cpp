#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

constexpr ll LINF = 9e18;

constexpr int MAXN = 1e5 + 5;
constexpr int B    = 316    ;

struct block_node {
    ll sum, mx;
    int cnt;
    int v[(B << 1) + 5];
    block_node *next;

    block_node() : cnt(0), sum(0), mx(0), next(nullptr) {}

    static void free_all(block_node *node) {
        while (node != nullptr) {
            block_node *nxt = node->next;
            delete node;
            node = nxt;
        }
    }
};

int n, q;
int a[MAXN], b[MAXN], idx[MAXN];

block_node *head, *tail;
block_node *pos[MAXN];

block_node *check_split(block_node *node) {
    if (node->cnt < 2 * B) return node;
    block_node *block = new block_node();
    for (int i = B; i < node->cnt; i++) {
        block->v[block->cnt++] = node->v[i];
        pos[block->v[block->cnt - 1]] = block;
    }

    block->cnt = node->cnt - B;
    node->cnt = B;
    block->next = node->next;
    node->next = block;
    return block;
}

bool check_before(const int i, const int j) {
    if (b[i] == b[j]) return i < j;
    return b[i] > b[j];
}

void update_block(block_node *block) {
    block->mx  = 0;
    block->sum = 0;
    for (int i = 0; i < block->cnt; i++) {
        int j = block->v[i];
        block->sum += a[j];
        block->mx = max(block->mx, block->sum + b[j]);
    }
}

void erase(int p) {
    block_node *node = pos[p];
    assert(node != nullptr && node->cnt != 0);
    pos[p] = nullptr;

    int j = -1;
    for (int i = 0; i < node->cnt; i++) {
        if (node->v[i] == p) {
            j = i;
            break;
        }
    }

    assert(j != -1);

    for (int i = j; i < node->cnt - 1; i++) {
        node->v[i] = node->v[i + 1];
    }

    --node->cnt;
    update_block(node);
}

void insert(int p) {
    block_node *prev = nullptr, *cur = head;
    while (cur != nullptr) {
        if (cur->cnt > 0 && check_before(p, cur->v[0])) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    if (prev == nullptr) prev = cur;

    int i = 0;
    while (i < prev->cnt && !check_before(p, prev->v[i])) {
        ++i;
    }

    for (int j = prev->cnt; j > i; --j) {
        prev->v[j] = prev->v[j - 1];
    }

    prev->v[i] = p;
    ++prev->cnt;
    pos[p] = prev;

    update_block(prev);

    block_node *sp = check_split(prev);
    if (sp != prev) {
        update_block(prev);
        update_block(sp);
    }
}

ll calculate() {
    ll sum = 0, ans = 0;
    block_node *node = head;
    while (node != nullptr) {
        ans = max(ans, sum + node->mx);
        sum += node->sum;
        node = node->next;
    }
    return ans;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) idx[i] = i;
    sort(idx + 1, idx + 1 + n, check_before);

    head = tail = new block_node();
    for (int i = 1; i <= n; i++) {
        tail->v[tail->cnt++] = idx[i];
        tail = check_split(tail);
    }

    block_node *cur = head;
    while (cur != nullptr) {
        update_block(cur);
        for (int i = 0; i < cur->cnt; i++) {
            int j = cur->v[i];
            pos[j] = cur;
        }
        cur = cur->next;
    }

    while (q--) {
        int o, i, x;
        cin >> o >> i >> x;
        if (o == 1) {
            a[i] = x;
            update_block(pos[i]);
        } else {
            erase(i);
            b[i] = x;
            insert(i);
        }

        cout << calculate() << endl;
    }

    block_node::free_all(head);
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