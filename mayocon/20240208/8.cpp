// https://atcoder.jp/contests/abc242/tasks/abc242_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> F(1e+6, 1);
mint C(int n, int r) {
    if (n < r) return 0;
    return F[n] / (F[n-r] * F[r]);
}

void solve() {
    int N, M, B, W;
    cin >> N >> M >> B >> W;
    vector<vector<mint>> X(N, vector<mint> (M, 0)), Y(N, vector<mint>(M, 0));

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (i*j >= B) {
                X[i][j] = C(i*j, B);
                for (int k = 1; k <= i; k++) {
                    for (int l = 1; l <= j; l++) {
                        if (i == k && j == l) continue;
                        X[i][j] -= C(i, k) *  C(j, l) * X[k][l];
                    }
                }
            }
            if (i*j >= W) {
                Y[i][j] = C(i*j, W);
                for (int k = 1; k <= i; k++) {
                    for (int l = 1; l <= j; l++) {
                        if (i == k && j == l) continue;
                        Y[i][j] -= C(i, k) *  C(j, l) * Y[k][l];
                    }
                }
            }
        }
    }

    mint ans = 0;
    for (int x = 1; x < N; x++) {
        for (int y = 1; y < M; y++) {
            for (int z = 1; z < N; z++) {
                for (int w = 1; w < M; w++) {
                    if (x+z > N || y+w > M) continue;
                    ans += (C(N, x)*C(M, y)*X[x][y])*(C(N-x,z)*C(M-y,w)*Y[z][w]);
                }
            }
        }
    }
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < 1e+6; x++) F[x] = F[x-1] * x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
