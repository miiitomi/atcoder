// https://atcoder.jp/contests/abc132/tasks/abc132_d
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

vector<mint> F(1e+6, 1);
mint C(int n, int r) {return F[n]/(F[n-r]*F[r]);}
mint H(int n, int r) {return C(n+r-1, r);}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<vector<mint>> dp(N-K+1, vector<mint>(K, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N-K; i++) {
        for (int k = 0; k < K; k++) {
            dp[i+1][k] += dp[i][k] * (K+i+1 - (K - 1 - k));
            if (k != K-1) dp[i+1][k+1] += dp[i][k] * (K-1-k);
        }
    }
    for (mint x : dp[N-K]) cout << (x / F[N-K]).val() << "\n";
}

int main() {
    for (int x = 2; x < 1e+6; x++) F[x] = F[x-1] * x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
