// https://atcoder.jp/contests/abc280/tasks/abc280_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    int N, P;
    cin >> N >> P;
    mint prob = P*((mint)100).inv();

    vector<mint> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = 1 + prob*dp[i-2] + (1 - prob)*dp[i-1];
    }

    cout << dp[N].val() << endl;
}
