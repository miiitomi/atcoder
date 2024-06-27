// https://atcoder.jp/contests/abc125/tasks/abc125_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<ll>> dp(N, vector<ll>(2, -INF));
    dp[0][0] = A[0];
    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + A[i];
        dp[i][1] = max(dp[i-1][0]-2*A[i-1], dp[i-1][1]+2*A[i-1]) - A[i];
    }
    ll ans = max(dp[N-1][0], dp[N-1][1]);
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
