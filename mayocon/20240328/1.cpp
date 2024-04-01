// https://atcoder.jp/contests/abc250/tasks/abc250_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<bool>> color(N,  vector<bool>(N, false));
    for (int j = 1; j < N; j++) color[j][0] = !color[j-1][0];
    for (int i = 0; i < N; i++) for (int j = 1; j < N; j++) color[i][j] = !color[i][j-1];
    vector<string> S(N*A, string(N*B, '.'));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (color[i][j]) {
                for (int k = 0; k < A; k++) {
                    for (int l = 0; l < B; l++) {
                        S[i*A + k][j*B + l] = '#';
                    }
                }                
            }
        }
    }

    for (string &s : S) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
