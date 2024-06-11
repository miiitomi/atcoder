// https://atcoder.jp/contests/abc333/tasks/abc333_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> F(3001, 1);
vector<mint> pow2(3001, 1);
mint C(int n, int r) {return F[n]/(F[n-r]*F[r]);};

void solve() {
    int N;
    cin >> N;
    vector<mint> dp(N+1, 0);
    dp[1] = 1;
    for (int K = 2; K <= N; K++) {
        mint ans = 0;
        for (int l = 1; l <= K-1; l++) {
            ans += C(K-1, l)*dp[K-l];
        }
        ans /= pow2[K] - 1;
        dp[K] = ans;
    }

    for (int K = 1; K <= N; K++) {
        mint ans = 0;
        for (int l = 0; l < K; l++) {
            ans += (1/pow2[K-1]) * C(K-1, l) * dp[N-l];
        }
        cout << ans.val() << " ";
    }
    cout << endl;
}

int main() {
    for (int x = 1; x <= 3000; x++) {
        F[x] = F[x-1] * x;
        pow2[x] = pow2[x-1] * 2;
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
