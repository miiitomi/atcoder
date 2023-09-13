#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    ll N, K;
    cin >> N >> K;
    set<ll> S;
    for (ll x = 1; x*x <= N; x++) {
        S.insert(x);
        S.insert(N/x);
    }
    vector<ll> V;
    V.reserve((int)S.size());
    for (int x : S) V.push_back(x);
    int M = (int)V.size();

    vector<vector<ll>> dp(K, vector<ll>(M, 0));
    for (int i = 0; i < (int)V.size(); i++) {
        if (i == 0) dp[0][i] = 1;
        else dp[0][i] = V[i] - V[i-1];
    }

    for (int k = 1; k < K; k++) {
        vector<ll> X(1+M, 0);
        for (int j = 0; j < M; j++) X[j+1] = (X[j] + dp[k-1][j]) % MOD;
        for (int i = 0; i < M; i++) {
            ll x = V[i];
            ll y = N / x;
            ll s = V[i];
            if (i != 0) s -= V[i-1];
            int j = distance(V.begin(), lower_bound(V.begin(), V.end(), y));
            dp[k][i] = s * X[j+1] % MOD;
        }
    }

    ll ans = 0;
    for (int i = 0; i < M; i++) ans = (ans + dp[K-1][i]) % MOD;

    cout << ans << endl;
}
