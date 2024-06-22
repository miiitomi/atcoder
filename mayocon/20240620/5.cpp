// https://atcoder.jp/contests/abc145/tasks/abc145_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll N, T;
    cin >> N >> T;
    vector<vector<ll>> dp(N+1, vector<ll>(6001, -INF));
    vector<pair<ll,ll>> P(N);
    for (int i = 0; i< N; i++) cin >> P[i].first >> P[i].second;
    sort(P.begin(), P.end());
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        ll a = P[i].first, b = P[i].second;
        for (int j = 0; j < T; j++) {
            dp[i+1][j+a] = max(dp[i+1][j+a], dp[i][j] + b);
        }
    }

    ll ans = *max_element(dp[N].begin(), dp[N].end());
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
