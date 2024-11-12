// https://atcoder.jp/contests/abc145/tasks/abc145_f
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
    vector<ll> H(N), v;
    v.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        v.push_back(H[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (ll &h : H) h = distance(v.begin(), lower_bound(v.begin(), v.end(), h));
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+1, vector<ll>(v.size(), INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            ll tmp1 = dp[i][j][0], tmp2 = INF;
            if (j > 0) tmp2 = dp[i][j-1][0];
            for (int k = 0; k < (int)v.size(); k++) {
                if (k > 0) {
                    tmp1 = min(tmp1+v[k]-v[k-1], dp[i][j][k]);
                    if (j > 0) tmp2 = min(tmp2+v[k]-v[k-1], dp[i][j-1][k]);
                }
                if (k == H[i]) dp[i+1][j][k] = min(dp[i+1][j][k], tmp1);
                else if (j > 0)  dp[i+1][j][k] = min(dp[i+1][j][k], tmp2);
            }
            tmp1 = INF; tmp2 = INF;
            for (int k = (int)v.size() - 1; k >= 0; k--) {
                tmp1 = min(tmp1, dp[i][j][k]);
                if (j > 0) tmp2 = min(tmp2, dp[i][j-1][k]);
                if (k == H[i]) dp[i+1][j][k] = min(dp[i+1][j][k], tmp1);
                else if (j > 0) dp[i+1][j][k] = min(dp[i+1][j][k], tmp2);
            }
        }
    }
    ll ans = INF;
    for (int j = 0; j <= K; j++) {
        for (int k = 0; k < (int)v.size(); k++) {
            ans = min(ans, dp[N][j][k]);
        }
    }
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
