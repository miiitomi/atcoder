// https://atcoder.jp/contests/abc345/tasks/abc345_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> C(N), V(N);
    for (int i = 0; i < N; i++) cin >> C[i] >> V[i];
    vector<vector<pair<ll,ll>>> dp(K+1, vector<pair<ll,ll>>(2, {-INF, 0}));
    dp[0][0] = {0, 0};
    for (int i = 0; i < N; i++) {
        vector<vector<pair<ll,ll>>> ndp(K+1, vector<pair<ll,ll>>(2, {-INF, 0}));
        for (int k = 0; k <= K; k++) {
            if (k > 0) ndp[k] = dp[k-1];
            pair<ll,ll> p = {-INF, C[i]};
            if (dp[k][0].second != C[i]) p.first = dp[k][0].first+V[i];
            else p.first = dp[k][1].first+V[i];

            if (ndp[k][0].second == p.second) {
                if (ndp[k][0].first < p.first) ndp[k][0] = p;
            } else if (ndp[k][0].first < p.first) {
                ndp[k][1] = ndp[k][0];
                ndp[k][0] = p;
            } else if (ndp[k][1].first < p.first) {
                ndp[k][1] = p;
            }
        }
        swap(dp, ndp);
    }

    if (dp[K][0].first >= 0) cout << dp[K][0].first << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
