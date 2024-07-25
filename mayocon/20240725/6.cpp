// https://atcoder.jp/contests/abc335/tasks/abc335_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
const ll B = 500;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<mint> dp(N, 0);
    vector<vector<mint>> sum(B+1, vector<mint>(B, 0));

    for (int i = N-1; i >= 0; i--) {
        if (A[i] <= B) {
            dp[i] += sum[A[i]][i % A[i]];
        } else {
            for (ll j = i + A[i]; j < N; j += A[i]) {
                dp[i] += dp[j];
            }
        }
        dp[i]++;
        for (ll b = 1; b <= B; b++) {
            sum[b][i%b] += dp[i];
        }
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
