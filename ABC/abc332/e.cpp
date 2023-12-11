#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double INF = 1e+18;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> W(N);
    double mean = 0;
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        mean += W[i];
    }
    mean /= D;

    vector<vector<double>> dp((1LL << N), vector<double>(D+1, INF));
    for (int s = 1; s < (1 << N); s++) {
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            if (s & (1 << i)) {
                sum += W[i];
            }
        }
        dp[s][1] = (sum - mean)*(sum - mean);
    }

    for (int k = 2; k <= D; k++) {
        for (int s = 1; s < (1 << N); s++) {
            int t = (s - 1) & s;
            while (t != 0) {
                dp[s][k] = min(dp[s][k], dp[s-t][k-1] + dp[t][1]);
                t = (t - 1) & s;
            }
        }
    }

    cout << fixed << setprecision(15) << dp[(1 << N)-1][D] / D << endl;
}
