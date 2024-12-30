// https://atcoder.jp/contests/abc076/tasks/abc076_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> T(N), V(N);
    for (int i = 0; i < N; i++) cin >> T[i];
    for (int i = 0; i < N; i++) cin >> V[i];
    vector<double> dp(1, 0);
    for (int i = 0; i < N; i++) {
        while ((int)dp.size() <= V[i]) dp.push_back(-INF);
        while ((int)dp.size() > V[i]+1) dp.pop_back();
        while (T[i]--) {
            vector<double> ndp(dp.size(), -INF);
            for (int v = 0; v <= V[i]; v++) {
                if (dp[v] < 0) continue;
                ndp[v] = max(ndp[v], dp[v]+v);
                if (v-1 >= 0) ndp[v-1] = max(ndp[v-1], dp[v]+(v+v-1.0)/2.0);
                if (v+1 <= V[i]) {
                    ndp[v+1] = max(ndp[v+1], dp[v]+(v+v+1.0)/2.0);
                    ndp[v] = max(ndp[v], dp[v]+v+1.0/4.0);
                }
            }
            swap(dp, ndp);
        }
    }
    cout << dp[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
