// https://atcoder.jp/contests/abc132/tasks/abc132_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
    ll N, K;
    cin >> N >> K;

    set<ll> S;
    map<ll, ll> f;
    for (ll x = 1; x*x <= N; x++) {
        if (!S.count(N/x)) {
            f[x] = N/x;
            f[N/x] = x;
            S.insert(x);
            S.insert(N/x);
        }
    }
    map<ll, int> idx;
    vector<ll> V;
    for (ll x : S) {
        V.push_back(x);
        idx[x] = (int)V.size();
    } 

    int M = V.size();

    vector<vector<ll>> dp(K, vector<ll>(M, 0));
    dp[0][0] = 1;
    for (int i = 1; i < M; i++) {
        dp[0][i] = (V[i] - V[i-1]) % MOD;
    }

    for (int k = 1; k < K; k++) {
        vector<ll> A(M+1, 0);
        for (int i = 0; i < M; i++) A[i+1] = (A[i] + dp[k-1][i]) % MOD;
        for (int i = 0; i < M; i++) {
            ll x = V[i];
            ll y = f[x];
            int j = idx[y];
            if (i == 0) dp[k][i] = A[j];
            else dp[k][i] = ((V[i] - V[i-1])) * A[j] % MOD;
        }
    }

    ll ans = 0;
    for (int i = 0; i < M; i++) ans = (ans + dp[K-1][i]) % MOD;
    cout << ans << endl;
}
