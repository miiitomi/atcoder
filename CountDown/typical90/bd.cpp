#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<int>> dp(N+1, vector<int>(S+1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S; j++) {
            if (dp[i][j] == -1) continue;
            if (j + A[i] <= S) dp[i+1][j + A[i]] = 0;
            if (j + B[i] <= S) dp[i+1][j + B[i]] = 1;
        }
    }

    if (dp[N][S] == -1) {
        cout << "Impossible" << endl;
        return 0;
    }

    string T;
    int j = S;
    for (int i = N; i >= 1; i--) {
        if (dp[i][j] == 0) {
            T.push_back('A');
            j -= A[i-1];
        } else {
            T.push_back('B');
            j -= B[i-1];
        }
    }
    reverse(T.begin(), T.end());
    cout << T << endl;
}
