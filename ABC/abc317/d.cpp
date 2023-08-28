#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> X(N), Y(N), Z(N);
    ll mz = 0;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        mz += Z[i];
    }
    mz = (mz / 2) + 1;

    vector<vector<ll>> dp(N+1, vector<ll>(mz+1, 1e+15));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        ll w = max((X[i]+Y[i]+1)/2 - X[i], 0LL);
        for (int j = 0; j <= mz; j++) {
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            dp[i+1][min(j+Z[i], mz)] = min(dp[i+1][min(j+Z[i], mz)], dp[i][j]+w);
        }
    }

    cout << dp[N][mz] << endl;
}
