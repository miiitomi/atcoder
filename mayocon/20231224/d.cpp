// https://atcoder.jp/contests/abc266/tasks/abc266_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int N;
    cin >> N;
    vector<int> T(N), X(N), A(N);
    for (int i = 0; i < N; i++) cin >> T[N-1-i] >> X[N-1-i] >> A[N-1-i];
    int M = T[0];

    vector<vector<ll>> dp(M + 1, vector<ll>(5, -1e+18));
    dp[0][0] = 0;
    for (int t = 0; t < M; t++) {
        for (int j = 0; j <= 4; j++) {
            for (int k = j-1; k <= j+1; k++) {
                if (!(0 <= k && k <= 4)) continue;
                if (!T.empty() && T.back() == t+1 && X.back() == k) dp[t+1][k] = max(dp[t+1][k], dp[t][j] + A.back());
                else dp[t+1][k] = max(dp[t+1][k], dp[t][j]);
            }
        }
        if (!T.empty() && t+1 == T.back()) {
            T.pop_back();
            A.pop_back();
            X.pop_back();
        }
    }

    cout << *max_element(dp[M].begin(), dp[M].end()) << endl;
}
