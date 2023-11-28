#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];
    vector<int> dp(N, 2e+9);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= K; k++) {
            if (i + k >= N) break;
            dp[i+k] = min(dp[i+k], dp[i] + abs(h[i] - h[i+k]));
        }
    }
    cout << dp.back() << endl;
}
