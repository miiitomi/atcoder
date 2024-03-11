// https://atcoder.jp/contests/abc275/tasks/abc275_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<mint>> dp(K+1, vector<mint>(N+1, 0));
    mint p = ((mint)M).inv();
    for (int k = 0; k <= K; k++) dp[k][N] = 1;
    for (int k = K-1; k >= 0; k--) {
        for (int i = 0; i < N; i++) {
            for (int m = 1; m <= M; m++) {
                int x = i + m;
                if (x > N) x = N - (x - N);
                dp[k][i] += p * dp[k+1][x];
            }
        }
    }
    cout << dp[0][0].val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
