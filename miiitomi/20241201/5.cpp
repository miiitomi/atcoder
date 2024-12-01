// https://atcoder.jp/contests/abc169/tasks/abc169_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> P(3001, 1);

void solve() {
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<mint>> dp(N+1, vector<mint>(S+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            dp[i+1][j] += 2*dp[i][j];
            if (j + A[i] <= S) dp[i+1][j+A[i]] += dp[i][j];
        }
    }
    cout << dp[N][S].val() << endl;
}

int main() {
    for (int x = 1; x <= 3000; x++) P[x] = P[x-1] * 2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
