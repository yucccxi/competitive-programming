#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int n = 1000, m = 1000;
    cout << 1 << '\n';
    cout << n << ' ' << m << '\n';

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (j % 2 == 1 ? 1 : -2);
            cout << (j == m ? '\n' : ' ');
        }
    }
}
