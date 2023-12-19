// https://atcoder.jp/contests/abc257/tasks/abc257_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> C(10, 0);
    for (int i = 1; i <= 9; i++) cin >> C[i];

    vector<int> dp(N+1, 0);
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= 9; k++) {
            if (i - C[k] >= 0) {
                dp[i] = max(dp[i], 1 + dp[i - C[k]]);
            }
        }
    }

    string S = "";
    while (dp[N] > 0) {
        int mx = -1;
        for (int k = 1; k <= 9; k++) {
            if (N - C[k] >= 0 && dp[N-C[k]] == dp[N]-1) {
                mx = k;
            }
        }
        N -= C[mx];
        S.push_back('0' + mx);
    }

    cout << S << endl;
}
