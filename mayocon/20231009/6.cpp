// https://atcoder.jp/contests/abc200/tasks/abc200_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<vector<ll>> dp(3, vector<ll>(3*N + 1, 0));
    for (int i = 1; i <= N; i++) dp[0][i] = 1;

    for (int i = 1; i <= 2; i++) {
        vector<ll> S(3*N+2, 0);
        for (int j = 0; j <= 3*N; j++) S[j+1] = S[j] + dp[i-1][j];
        for (int j = 2; j <= 3*N; j++) {
            int min_j = max(1LL, j - N);
            dp[i][j] = S[j] - S[min_j];
        }
    }

    ll x;
    for (int i = 3; i <= 3*N; i++) {
        if (K <= dp[2][i]) {
            x = i;
            break;
        }
        K -= dp[2][i];
    }

    for (int i = 1; i <= N; i++) {
        if (x - i > 2*N) continue;
        int min_j = max(1LL, x-i-N), max_j = min(N, x-i-1);
        if (K > max_j - min_j + 1) K -= (max_j - min_j + 1);
        else {
            int j = K - 1 + min_j;
            int k = x - i - j;
            cout << i << " " << j << " " << k << endl;
            return 0;
        }
    }
}
