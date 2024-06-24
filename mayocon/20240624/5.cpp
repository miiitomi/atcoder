// https://atcoder.jp/contests/abc298/tasks/abc298_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

void solve() {
    int N, A, B, P, Q;
    cin >> N >> A >> B >> P >> Q;

    vector<vector<mint>> dp(N+1, vector<mint>(N+1, 0));
    mint p = ((mint)(P*Q)).inv();
    for (int x = N; x >= 0; x--) {
        for (int y = N; y >= 0; y--) {
            if (x == N) dp[x][y] = 1;
            else if (y == N) dp[x][y] = 0;
            else {
                for (int a = 1; a <= P; a++) {
                    for (int b = 1; b <= Q; b++) {
                        int s = min(x+a, N), t = min(y+b, N);
                        dp[x][y] += p*dp[s][t];
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
