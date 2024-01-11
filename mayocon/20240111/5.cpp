// https://atcoder.jp/contests/abc280/tasks/abc280_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    int N, P;
    cin >> N >> P;
    mint p = P*((mint)100).inv();
    mint q = 1 - p;
    vector<mint> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int x = 2; x <= N; x++) {
        dp[x] = 1 + dp[x-1]*q + dp[x-2]*p;
    }

    cout << dp[N].val() << endl;
}
