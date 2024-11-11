// https://atcoder.jp/contests/abc243/tasks/abc243_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(51, 1), I(51, 1);

void solve() {
    ll N, M, K;
    mint S = 0;
    cin >> N >> M >> K;
    vector<ll> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        S += W[i];
    }
    vector<mint> p(N);
    for (int i = 0; i < N; i++) p[i] = W[i]*S.inv();
    vector<vector<vector<mint>>> dp(N+1, vector<vector<mint>>(M+1, vector<mint>(K+1, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= K; k++) {
                dp[i+1][j][k] += dp[i][j][k];
                if (j == M) continue;
                mint q = p[i];
                for (int l = 1; l + k <= K; l++) {
                    dp[i+1][j+1][k+l] += dp[i][j][k] * q * I[l];
                    q *= p[i];
                }
            }
        }
    }
    mint ans = dp[N][M][K] * F[K];
    cout << ans.val() << endl;
}

int main() {
    for (int i = 1; i <= 50; i++) {
        F[i] = i * F[i-1];
        I[i] = F[i].inv();
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
