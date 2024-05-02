// https://atcoder.jp/contests/abc288/tasks/abc288_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void chmin(ll &l, ll r) {if (l > r) l = r;}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), C(N);
    vector<vector<ll>> T(N, vector<ll>(N, INF));
    vector<bool> X(N, false);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (j > i) T[i][j] = T[i][j-1];
            chmin(T[i][j], C[j]);
        }
    }
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        X[x-1] = true;
    }

    vector<vector<ll>> dp(N+1, vector<ll>(N+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            if (dp[i][j] == INF) continue;
            chmin(dp[i+1][j+1], dp[i][j] + A[i] + T[i-j][i]);
            if (!X[i]) chmin(dp[i+1][j], dp[i][j]);
        }
    }
    ll ans = INF;
    for (int j = M; j <= N; j++) chmin(ans, dp[N][j]);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
