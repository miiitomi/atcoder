// https://atcoder.jp/contests/abc298/tasks/abc298_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void solve() {
    int N, A, B, P, Q;
    cin >> N >> A >> B >> P >> Q;
    vector<vector<mint>> dp(N+1, vector<mint>(N+1, 0));
    mint prob = ((mint)P * Q).inv();
    for (int x = N; x >= 1; x--) {
        for (int y = N; y >= 1; y--) {
            if (x == N) dp[x][y] = 1;
            else if (y == N) dp[x][y] = 0;
            else {
                for (int p = 1; p <= P; p++) {
                    for (int q = 1; q <= Q; q++) {
                        if (x + p >= N) dp[x][y] += prob;
                        else if (y + q >= N) dp[x][y] += 0;
                        else dp[x][y] += prob * dp[x+p][y+q];
                    }
                }
            }
        }
    }
    cout << dp[A][B].val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
