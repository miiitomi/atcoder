// https://atcoder.jp/contests/abc088/tasks/abc088_c
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e+6;

void solve() {
    vector<vector<int>> c(3, vector<int>(3));
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> c[i][j];

    vector<int> a(3), b(3);
    for (a[0] = -INF; a[0] <= INF; a[0]++) {
        b[0] = c[0][0] - a[0];
        b[1] = c[0][1] - a[0];
        b[2] = c[0][2] - a[0];
        a[1] = c[1][0] - b[0];
        a[2] = c[2][0] - b[0];
        vector<vector<int>> d(3, vector<int>(3));
        for (int i = 0; i < 3; i++) {
            for (int j= 0; j < 3; j++) {
                d[i][j] = a[i] + b[j];
            }
        }
        if (c == d) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
