#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(501, 1);
vector<vector<mint>> C(501, vector<mint>(501, 0));
vector<mint> POW_M(500*500 + 1, 1);

void solve() {
    int N, M;
    cin >> N >> M;
    for (int x = 1; x <= 500*500; x++) POW_M[x] = POW_M[x-1] * M;
    mint ans = (N-1 - M)*POW_M[N*(N-1)/2];
    for (int k = 1; k <= M; k++) {
        vector<mint> POW_M_k(500*500 + 1, 1);
        for (int x = 1; x <= 500*500; x++) POW_M_k[x] = POW_M_k[x-1] * (M-k);
        vector<mint> f(N+1);
        for (int S = 1; S <= N; S++) {
            f[S] = POW_M[S*(S-1)/2];
            for (int T = 1; T <= S-1; T++) {
                f[S] -= C[S-1][T-1]*f[T]*POW_M_k[T*(S-T)]*POW_M[(S-T)*(S-T-1)/2];
            }
            ans += C[N][S]*f[S]*POW_M_k[S*(N-S)]*POW_M[(N-S)*(N-S-1)/2];
        }
    }
    cout << ans.val() << "\n";
}

int main() {
    for (int x = 1; x <= 500; x++) F[x] = F[x-1]*x;
    for (int n = 0; n <= 500; n++) for (int r = 0; r <= n; r++) C[n][r] = F[n]/(F[n-r]*F[r]);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
