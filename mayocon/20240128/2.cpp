// https://atcoder.jp/contests/abc239/tasks/abc239_d
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int N) {
    if (N <= 1) return false;
    for (int x = 2; x < N; x++) {
        if (N % x == 0) return false;
    }
    return true;
}

void solve() {
    bool aoki_win = true;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int x = a; x <= b; x++) {
        bool tmp = false;
        for (int y = c; y <= d; y++) {
            if (is_prime(x + y)) tmp = true;
        }
        if (!tmp) aoki_win = false;
    }

    if (aoki_win) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
