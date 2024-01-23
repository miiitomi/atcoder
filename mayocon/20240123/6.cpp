// https://atcoder.jp/contests/abc315/tasks/abc315_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double d(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    double all_penalty = 0;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        if (i > 0) all_penalty += d(X[i-1], Y[i-1], X[i], Y[i]);
    }
    ll C = 0;
    while ((1LL << C) <= all_penalty + 2) C++;

    vector<vector<double>> dp(N, vector<double>(1+C, 1e+18));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int c = 0; c <= C; c++) {
            for (int k = 0; k <= C; k++) {
                int j = i + 1 + k;
                if (j >= N || c+k > C) break;
                dp[j][c+k] = min(dp[j][c+k], dp[i][c] + d(X[i], Y[i], X[j], Y[j]));
            }
        }
    }
    double ans = dp[N-1][0];
    for (ll c = 1; c <= C; c++) ans = min(ans, dp[N-1][c] + (1LL << (c - 1LL)));

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
