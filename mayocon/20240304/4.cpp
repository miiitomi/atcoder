// https://atcoder.jp/contests/abc261/tasks/abc261_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> X(N+1, 0), Y(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> X[i];
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        cin >> Y[c];
    }
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));
    for (int i = N; i >= 1; i--) {
        for (int j = 0; j < N; j++) {
            dp[i-1][j] = max(dp[i][j+1]+X[i]+Y[j+1], dp[i][0]);
        }
    }
    cout << dp[0][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
