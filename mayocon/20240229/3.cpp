// https://atcoder.jp/contests/abc184/tasks/abc184_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if (r1 == r2 && c1 == c2) {
        cout << 0 << endl;
        return;
    }

    if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2 || abs(r1 - r2) + abs(c1 - c2) <= 3) {
        cout << 1 << endl;
        return;
    }

    if ((r1 + c1)%2 == (r2 + c2) % 2) {
        cout << 2 << endl;
        return;
    }

    for (int s = -3; s <= 3; s++) {
        for (int t = -3; t <= 3; t++) {
            if (abs(s) + abs(t) > 3) continue;
            int x = r1 + s, y = c1 + t;
            if (x + y== r2 + c2 || x - y == r2 - c2 || abs(x - r2) + abs(y - c2) <= 3) {
                cout << 2 << endl;
                return;
            }
            x = r2 + s;
            y = c2 + t;
            if (r1 + c1 == x + y || r1 - c1 == x - y || abs(r1 - x) + abs(c1 - y) <= 3) {
                cout << 2 << endl;
                return;
            }
        }
    }

    cout << 3 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
