// https://atcoder.jp/contests/abc266/tasks/abc266_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> dp(N+1, 0.0);
    dp[1] = 3.5;

    for (int i = 2; i <= N; i++) {
        for (int x = 1; x <= 6; x++) {
            if (x > dp[i-1]) dp[i] += x;
            else dp[i] += dp[i-1];
        }
        dp[i] /= 6.0;
    }

    cout << fixed << setprecision(15) << dp[N] << endl;
}
