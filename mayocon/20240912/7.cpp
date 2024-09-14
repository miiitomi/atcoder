// https://atcoder.jp/contests/abc238/tasks/abc238_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll,ll>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i].first;
        P[i].first = N - P[i].first;
    }
    for (int i = 0; i < N; i++) {
        cin >> P[i].second;
        P[i].second = N - P[i].second;
    }
    sort(P.begin(), P.end());

    vector<vector<mint>> dp(K+1, vector<mint>(N+1, 0));
    dp[0][N] = 1;
    for (int i = 0; i < N; i++) {
        vector<vector<mint>> ndp(K+1, vector<mint>(N+1, 0));
        for (int k = 0; k <= K; k++) {
            for (int l = 0; l <= N; l++) {
                if (l <= P[i].second) {
                    if (k+1 <= K) ndp[k+1][l] += dp[k][l];
                } else {
                    if (k+1 <= K) ndp[k+1][P[i].second] += dp[k][l];
                    ndp[k][l] += dp[k][l];
                }
            }
        }
        swap(dp, ndp);
    }
    mint ans = 0;
    for (int l = 0; l <= N; l++) ans += dp[K][l];
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
