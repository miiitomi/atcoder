// https://atcoder.jp/contests/abc239/tasks/abc239_d
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    if (x <= 1) return false;
    for (int y = 2; y < x; y++) {
        if (x % y == 0) return false;
    }
    return true;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int x = a; x <= b; x++) {
        bool aoki_can_win = false;
        for (int y = c; y <= d; y++) {
            if (is_prime(x + y)) aoki_can_win = true;
        }

        if (!aoki_can_win) {
            cout << "Takahashi\n";
            return;
        }
    }
    cout << "Aoki\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
