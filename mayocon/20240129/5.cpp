// https://atcoder.jp/contests/abc326/tasks/abc326_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N+1, 0);
    for (int i = 0; i < N; i++) cin >> A[i+1];
    vector<mint> dp(N+1, 0);
    mint s = A[N];
    mint p = ((mint)N).inv();
    for (int i = N-1; i >= 0; i--) {
        dp[i] = p * s;
        s += dp[i] + A[i];
    }
    cout << dp[0].val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
