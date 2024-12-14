// https://atcoder.jp/contests/abc229/tasks/abc229_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, sum = 0;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < 2*N; i++) {
        ll a;
        cin >> a;
        if (i < N) A[i] = a;
        else B[i-N] = a;
        sum += a;
    }
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(2, vector<ll>(2, -INF)));
    dp[0][0][0] = 0;
    dp[0][1][1] = A[0];
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[i][j][k] < 0) continue;
                for (int l = 0; l < 2; l++) {
                    dp[i+1][l][k] = max(dp[i+1][l][k], dp[i][j][k] + (j != l) * B[i] + (l == 1) * A[i+1] + (i+1 == N-1 && l != k) * B[i+1]);
                }
            }
        }
    }
    ll ans = INF;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
            ans = min(ans, sum - dp.back()[j][k]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
