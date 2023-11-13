#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<mint> dp(N+1, 0);
    mint prob = ((mint)N).inv();
    mint s = 0;

    for (int i = N-1; i >= 0; i--) {
        s += A[i];
        s += dp[i+1];
        dp[i] = prob * s;
    }

    cout << dp[0].val() << endl;
}
