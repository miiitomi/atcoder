// https://atcoder.jp/contests/abc317/tasks/abc317_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> X(N), Y(N), Z(N);
    ll sum_z = 0;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        sum_z += Z[i];
    }
    ll W = (sum_z+1) / 2;
    vector<vector<ll>> dp(N+1, vector<ll>(W+1, 1e+17));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        ll z = Z[i];
        ll dw;
        if (X[i] > Y[i]) dw = 0;
        else dw = (X[i] + Y[i] + 1) / 2 - X[i];
        for (int w = 0; w <= W; w++) {
            dp[i+1][w] = min(dp[i+1][w], dp[i][w]);
            dp[i+1][min(w + z, W)] = min(dp[i+1][min(w + z, W)], dp[i][w] + dw);
        }
    }

    cout << dp[N][W] << endl;
}
