// https://atcoder.jp/contests/abc195/tasks/abc195_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    string S, X;
    cin >> N >> S >> X;

    vector<vector<bool>> dp(N+1, vector<bool>(7, false));
    dp[N][0] = true;

    for (int i = N-1; i >= 0; i--) {
        int a = S[i] - '0';
        if (X[i] == 'T') {
            for (int x = 0; x < 7; x++) {
                int y = (10*x + a) % 7, z = (10*x) % 7;
                if (dp[i+1][z] || dp[i+1][y]) dp[i][x] = true;
                else dp[i][x] = false;
            }
        } else {
            for (int x = 0; x < 7; x++) {
                int y = (10*x + a) % 7, z = (10*x) % 7;
                if (dp[i+1][z] == false || dp[i+1][y] == false) dp[i][x] = false;
                else dp[i][x] = true;
            }
        }
    }

    if (dp[0][0]) cout << "Takahashi\n";
    else cout << "Aoki\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
