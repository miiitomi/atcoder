#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];
    vector<int> dp(N, 2e+9);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (i + 1 <= N-1) dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        if (i + 2 <= N-1) dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
    }
    cout << dp[N-1] << endl;
}
