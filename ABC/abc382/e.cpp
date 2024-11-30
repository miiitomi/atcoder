#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, X;
    cin >> N >> X;
    vector<ll> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    vector<double> dp(X+1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        vector<double> ndp(X+1, 0);
        for (int j = 0; j <= X; j++) {
            ndp[j] += dp[j]*(100.0 - P[i])/100.0;
            ndp[min(j+1LL, X)] += dp[j]*(0.0+P[i])/100.0;
        }
        swap(dp, ndp);
    }

    vector<double> ep(X+1, 0);
    for (int j = X-1; j >= 0; j--) {
        double tmp = 1;
        for (int k = 1; k <= X; k++) {
            tmp += dp[k]*ep[min(j+k+0LL, X)];
        }
        tmp /= (1.0 - dp[0]);
        ep[j] = tmp;
    }
    cout << ep[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
