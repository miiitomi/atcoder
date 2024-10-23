#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> void chmin(T &v, T nv) {
    if (v > nv) v = nv;
}

void solve() {
    ll N, H;
    cin >> N >> H;
    vector<ll> X(N+1), P(N+1, 0), F(N+1, 0);
    for (int i = 0; i < N; i++) cin >> X[1+i];
    for (int i = 0; i < N-1; i++) cin >> P[1+i] >> F[1+i];
    vector dp(N+1, vector(H+1, vector(H+1, INF)));
    for (int i = 0; i <= H; i++) dp[N][i][i] = 0;

    for (int i = N-1; i >= 0; i--) {
        for (int a = 0; a <= H; a++) {
            for (int b = 0; b <= H; b++) {
                if (a >= X[i+1]-X[i]) {
                    if (b+(X[i+1]-X[i]) <= H) chmin(dp[i][a][b], dp[i+1][a-(X[i+1]-X[i])][b+(X[i+1]-X[i])]);
                    if (b-F[i] >= 0 && b-F[i]+(X[i+1]-X[i]) <= H) {
                        chmin(dp[i][a][b], dp[i+1][a-(X[i+1]-X[i])][b+(X[i+1]-X[i])-F[i]]+P[i]);
                    }
                    if (b == H) {
                        for (int c = 0; c <= H; c++) {
                            if (c+F[i]>=H && c+(X[i+1]-X[i])<=H) {
                                chmin(dp[i][a][b], dp[i+1][a-(X[i+1]-X[i])][c+(X[i+1]-X[i])]+P[i]);
                            }
                        }
                    }
                }
                if (b+(X[i+1]-X[i]) <= H) {
                    if (a+F[i] <= H && X[i+1]-X[i] <= a+F[i]) chmin(dp[i][a][b], dp[i+1][a+F[i]-(X[i+1]-X[i])][b+(X[i+1]-X[i])]+P[i]);
                    if (a+F[i] > H && X[i+1]-X[i] <= H) chmin(dp[i][a][b], dp[i+1][H-(X[i+1]-X[i])][b+(X[i+1]-X[i])]+P[i]);
                }
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i <= H; i++) chmin(ans, dp[0][H][i]);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
