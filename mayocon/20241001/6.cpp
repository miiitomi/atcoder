// https://atcoder.jp/contests/abc217/tasks/abc217_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(1e+5, 1);
mint comb(int n, int r) {return F[n]/(F[n-r]*F[r]);};
vector<vector<mint>> C;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<bool>> A(2*N, vector<bool>(2*N, false));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u][v] = true;
        A[v][u] = true;
    }
    vector<vector<mint>> dp(2*N+1, vector<mint>(2*N+1, 0));
    for (int i = 0; i <= 2*N; i++) dp[i][i] = 1;
    for (int i = 0; i+1 < 2*N; i++) {
        if (A[i][i+1]) dp[i][i+2] = 1;
    }
    for (int K = 2; K <= N; K++) {
        for (int l = 0; l + 2*K <= 2*N; l++) {
            int r = l + 2*K;
            for (int i = l; i < r; i += 2) {
                for (int j = i+2; j <= r; j += 2) {
                    if (!A[i][j-1]) continue;
                    dp[l][r] += C[K-1][(i-l)/2] * C[K-1-(i-l)/2][(r-j)/2] * dp[l][i] * dp[i+1][j-1] * dp[j][r];
                }
            }
        }
    }
    cout << dp[0][2*N].val() << endl;
}

int main() {
    for (int x = 1; x < (int)1e+5; x++) F[x] = F[x-1]*x;
    C.assign(1000, vector<mint>(1000, 0));
    for (int n = 0; n < 1000; n++) for (int r = 0; r <= n; r++) C[n][r] = comb(n, r);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
