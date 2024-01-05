// https://atcoder.jp/contests/abc333/tasks/abc333_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> F(1e+4, 1), P2(1e+4, 1);
mint C(int n, int r) {return F[n] / (F[n-r]*F[r]);}


int main() {
    for (int x = 1; x < 1e+4; x++) {
        F[x] = F[x-1] * x;
        P2[x] = P2[x-1] * 2;
    }

    int N;
    cin >> N;

    vector<mint> dp(N+1, 0);
    dp[1] = 1;
    for (int k = 2; k <= N; k++) {
        for (int l = 0; l <= k-2; l++) dp[k] += C(k-1, l)*dp[l+1];
        dp[k] *= (P2[k] - 1).inv();
    }

    for (int i = 1; i <= N; i++) {
        mint ans = 0;
        for (int l = 0; l <= i-1; l++) ans += C(i-1, l) * dp[N-l];
        ans *= P2[i-1].inv();
        cout << ans.val() << " ";
    }
    cout << endl;
}
