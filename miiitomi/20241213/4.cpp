// https://atcoder.jp/contests/abc185/tasks/abc185_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void chmin(ll &v, ll nv) {
    if (v > nv) v = nv;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i < N) chmin(dp[i+1][j], dp[i][j] + 1);
            if (j < M) chmin(dp[i][j+1], dp[i][j] + 1);
            if (i < N && j < M) chmin(dp[i+1][j+1], dp[i][j] + (A[i] != B[j]));
        }
    }
    cout << dp.back().back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
