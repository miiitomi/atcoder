// https://atcoder.jp/contests/abc239/tasks/abc239_d
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int N) {
    for (int x = 2; x*x <= N; x++) {
        if (N%x == 0) return false;
    }
    return true;
}

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    for (int x = A; x <= B; x++) {
        bool aoki_can_win = false;
        for (int y = C; y <= D; y++) {
            if (is_prime(x + y)) {
                aoki_can_win = true;
                break;
            }
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
