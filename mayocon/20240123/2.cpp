// https://atcoder.jp/contests/abc225/tasks/abc225_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> B(N, vector<int>(M));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> B[i][j];
        B[i][j]--;
    }

    int x = B[0][0] / 7, y = B[0][0] % 7;
    bool is_ok = y + M-1 <= 6;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int b = B[i][j], s = x+i, t = y+j;
            if (b != s*7 + t) is_ok = false;
        }
    }

    if (is_ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
