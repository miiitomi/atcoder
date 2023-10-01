#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e+18;


ll pow_(ll a, ll n) {
    ll x = 1;
    for (int i = 0; i < n; i++) x *= a;
    return x;
}


int main() {
    ll N, K, P;
    cin >> N >> K >> P;
    vector<ll> C(N);
    vector<vector<ll>> A(N,vector<ll>(K));
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < K; j++) cin >> A[i][j];
    }

    vector<vector<ll>> dp(N+1, vector<ll>(pow_(P+1, K+1), INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (ll k = 0; k < pow_(P+1, K+1); k++) {
            if (dp[i][k] == INF) continue;
            dp[i+1][k] = min(dp[i+1][k], dp[i][k]);
            ll s = k;
            for (int j = 0; j < K; j++) {
                s -= (k / pow_(P+1, j)) * pow_(P+1, j) % pow_(P+1, j+1);
                s += min(P, (k / pow_(P+1, j)) % (P+1) + A[i][j]) * pow_(P+1, j);
            }
            dp[i+1][s] = min(dp[i+1][s], dp[i][k] + C[i]);
        }
    }

    ll ans = dp[N][pow_(P+1, K)-1];
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
