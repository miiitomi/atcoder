// https://atcoder.jp/contests/abc245/tasks/abc245_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    vector<vector<bool>> dp(N, vector<bool>(2, false));

    dp[0][0] = true;
    dp[0][1] = true;
    for (int i = 1; i < N; i++) {
        if (dp[i-1][0]) {
            if (abs(A[i-1] - A[i]) <= K) dp[i][0] = true;
            if (abs(A[i-1] - B[i]) <= K) dp[i][1] = true;
        }
        if (dp[i-1][1]) {
            if (abs(B[i-1] - A[i]) <= K) dp[i][0] = true;
            if (abs(B[i-1] - B[i]) <= K) dp[i][1] = true;
        }

        if (!(dp[i][0] || dp[i][1])) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
