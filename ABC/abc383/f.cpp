#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, X, K;
    cin >> N >> X >> K;
    vector<vector<pair<ll,ll>>> V(N);
    for (int i = 0; i < N; i++) {
        ll p, u, c;
        cin >> p >> u >> c;
        c--;
        V[c].push_back({p, u});
    }
    vector<ll> dp(X+1, 0);
    for (int c = 0; c < N; c++) {
        ll n = V[c].size();
        if (n == 0) continue;
        vector<vector<vector<ll>>> ep(n+1, vector<vector<ll>>(2, dp));
        for (int i = 0; i < n; i++) {
            auto [p, u] = V[c][i];
            for (int j = 0; j<= X; j++) {
                ep[i+1][1][j] = max(ep[i][1][j], ep[i+1][1][j]);
                if (j-p >= 0) ep[i+1][1][j] = max(ep[i+1][1][j], max(ep[i][0][j-p]+u+K, ep[i][1][j-p]+u));
            }
        }
        for (int j = 0; j <= X; j++) dp[j] = max(ep.back()[0][j], ep.back()[1][j]);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
