// https://atcoder.jp/contests/abc126/tasks/abc126_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    vector<double> dp(max(N+1, 2*K+1), 0);
    for (int x = dp.size()-1; x >= 1; x--) {
        if (x >= K) dp[x] = 1;
        else dp[x] = 0.5*dp[2*x];
    }

    double ans = 0;
    for (int x = 1; x <= N; x++) ans += dp[x] / N;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
