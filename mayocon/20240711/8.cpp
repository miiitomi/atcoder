// https://atcoder.jp/contests/abc242/tasks/abc242_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(1e+6, 1);
vector<vector<mint>> comb(100, vector<mint>(100, 0));
mint C(int n, int r) {
    if (r > n) return 0;
    if (n < 100) return comb[n][r];
    return F[n]/(F[n-r]*F[r]);
}

vector<vector<mint>> make_table_f(int N, int M, int K) {
    vector<vector<mint>> f(N+1, vector<mint>(M+1, 0));
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++) {
            if (x*y < K) continue;
            f[x][y] = C(x*y, K);
            for (int i = x; i > 0; i--) {
                for (int j = y; j > 0; j--) {
                    if (i*j < K) break;
                    if (i == x && j == y) continue;
                    f[x][y] -= C(x, i)*C(y, j)*f[i][j];
                }
            }
        }
    }
    return f;
}

void solve() {
    int N, M, B, W;
    cin >> N >> M >> B >> W;
    vector<vector<mint>> f = make_table_f(N, M, B), g = make_table_f(N, M, W);
    mint ans = 0;
    for (int nb = 1; nb < N; nb++) {
        for (int mb = 1; mb < M; mb++) {
            for (int nw = 1; nw + nb <= N; nw++) {
                for (int mw = 1; mw + mb <= M; mw++) {
                    ans += C(N, nb)*C(N-nb, nw)*C(M, mb)*C(M-mb, mw)*f[nb][mb]*g[nw][mw];
                }
            }
        }
    }
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < (int)1e+6; x++) F[x] = x*F[x-1];
    for (int n = 0; n < 100; n++) {
        for (int r = 0; r <= n; r++) {
            comb[n][r] = F[n]/(F[n-r]*F[r]);
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
