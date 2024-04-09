// https://atcoder.jp/contests/abc100/tasks/abc100_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int D, N;
    cin >> D >> N;
    int cnt = 0;
    for (int x = 1; x < 1e+7; x++) {
        int y = x;
        int tmp = 0;
        while (y % 100 == 0) {
            tmp++;
            y /= 100;
        }
        if (tmp == D) {
            cnt++;
            if (cnt == N) {
                cout << x << endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
