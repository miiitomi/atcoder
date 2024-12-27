// https://atcoder.jp/contests/abc071/tasks/arc081_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<string> S(2);
    for (int i = 0; i < 2; i++) cin >> S[i];
    vector<vector<vector<mint>>> dp(N, vector<vector<mint>>(3, vector<mint>(3, 0)));
    if (S[0][0] == S[1][0]) {
        dp[0][0][0] = 1;
        dp[0][1][1] = 1;
        dp[0][2][2] = 1;
    } else {
        dp[0][0][1] = 1;
        dp[0][0][2] = 1;
        dp[0][1][0] = 1;
        dp[0][1][2] = 1;
        dp[0][2][0] = 1;
        dp[0][2][1] = 1;
    }
    for (int i = 0; i+1 < N; i++) {
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                for (int c = 0; c < 3; c++) {
                    for (int d = 0; d < 3; d++) {
                        bool ok = true;
                        if (S[0][i+1] == S[1][i+1] && c != d) ok = false;
                        if (S[0][i+1] != S[1][i+1] && c == d) ok = false;
                        if (S[0][i] == S[0][i+1] && a != c) ok = false;
                        if (S[0][i] != S[0][i+1] && a == c) ok = false;
                        if (S[1][i] == S[1][i+1] && b != d) ok = false;
                        if (S[1][i] != S[1][i+1] && b == d) ok = false;
                        if (ok) dp[i+1][c][d] += dp[i][a][b];
                    }
                }
            }
        }
    }
    mint ans = 0;
    for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) ans += dp[N-1][a][b];
    cout << ans.val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
