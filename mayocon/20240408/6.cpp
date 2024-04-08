// https://atcoder.jp/contests/abc162/tasks/abc162_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void chmax(ll &x, ll y) {if (x < y) x = y;}

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(3, vector<ll>(2, -INF)));
    dp[0][1][0] = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int k = 0; k < 3; k++) {
                chmax(dp[i+1][k][0], max(dp[i][k][0], dp[i][k][1]));
                if (k < 2) chmax(dp[i+1][k+1][1], dp[i][k][0] + A[i]);
            }
        } else {
            for (int k = 0; k < 3; k++) {
                if (k >= 1) chmax(dp[i+1][k-1][0], max(dp[i][k][0], dp[i][k][1]));
                chmax(dp[i+1][k][1], dp[i][k][0] + A[i]);
            }
        }
    }

    cout << max(dp[N][1][0], dp[N][1][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
