// https://atcoder.jp/contests/abc262/tasks/abc262_d
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    mint ans = N;
    for (ll K = 2; K <= N; K++) {
        vector<vector<mint>> dp(K+1, vector<mint>(K, 0));
        dp[0][0] = 1;
        for (int i = 0; i < N; i++) {
            vector<vector<mint>> ndp = dp;
            for (int k = 0; k <= K-1; k++) {
                for (int x = 0; x < K; x++) {
                    ndp[k+1][(x + a[i]) % K] += dp[k][x];
                }
            }
            swap(dp, ndp);
        }
        ans += dp[K][0];
    }

    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
