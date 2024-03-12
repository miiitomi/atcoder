// https://atcoder.jp/contests/abc249/tasks/abc249_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint;

void solve() {
    int N, P;
    cin >> N >> P;
    mint::set_mod(P);

    vector<vector<mint>> dp(N+2, vector<mint>(N+2, 0));
    dp[0][0] = 1;
    dp[0][1] = -1;

    for (int s = 0; s <= N; s++) {
        for (int t = 0; t <= N; t++) {
            dp[t][s+1] += dp[t][s];
            mint a = dp[t][s] * 25;
            if (s == 0 && t == 0) a = 26;
            if (t + 2 <= N) {
                int d = min(9, N-s);
                if (d >= 1) {
                    dp[t+2][s+1] += a;
                    dp[t+2][s+d+1] -= a;
                }
            }
            if (t + 3 <= N) {
                int d = min(99, N-s);
                if (d >= 10) {
                    dp[t+3][s+10] += a;
                    dp[t+3][s+d+1] -= a;
                }
            }
            if (t + 4 <= N) {
                int d = min(999, N-s);
                if (d >= 100) {
                    dp[t+4][s+100] += a;
                    dp[t+4][s+d+1] -= a;
                }
            }
            if (t + 5 <= N) {
                int d = min(9999, N-s);
                if (d >= 1000) {
                    dp[t+5][s+1000] += a;
                    dp[t+5][s+d+1] -= a;
                }
            }
        }
    }

    mint ans = 0;
    for (int t = 0; t < N; t++) {
        ans += dp[t][N];
    }
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
