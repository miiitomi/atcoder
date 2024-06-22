// https://atcoder.jp/contests/abc162/tasks/abc162_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(2, vector<ll>(2, -INF)));
    dp[0][1][0] = 0;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            dp[i+1][0][0] = max(dp[i][1][0], dp[i][1][1]);
            dp[i+1][0][1] = dp[i][0][0] + A[i];
            dp[i+1][1][1] = dp[i][1][0] + A[i];
        } else {
            dp[i+1][0][0] = max(dp[i][0][0], dp[i][0][1]);
            dp[i+1][1][0] = max(dp[i][1][0], dp[i][1][1]);
            dp[i+1][1][1] = dp[i][0][0] + A[i];
        }
    }

    if (N % 2 == 0) cout << max(dp[N][1][0], dp[N][1][1]) << endl;
    else cout << max(dp[N][0][0], dp[N][0][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
