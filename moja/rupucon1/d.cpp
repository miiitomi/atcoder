#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll modinv(ll a) {
    // Check if a and MOD are coprime.
    ll b = MOD, u = 1, v = 0;
    while (b > 0) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}
vector<ll> inv(1001, 1);

int main() {
    for (ll x = 1; x <= 1000; x++) inv[x] = modinv(x);

    int N, M, T;
    cin >> N >> M >> T;

    vector<vector<pair<ll, ll>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--;
        v--;
        G[u].push_back(make_pair(v, t));
        G[v].push_back(make_pair(u, t));
    }

    vector<vector<ll>> dp(T+1, vector<ll>(N, 0));
    dp[0][0] = 1;

    for (int t = 0; t < T; t++) {
        for (int u = 0; u < N; u++) {
            if (u == N-1) {
                dp[t+1][u] = (dp[t+1][u] + dp[t][u]) % MOD;
                continue;
            }
            ll p = inv[(int)G[u].size()];
            for (auto &e : G[u]) {
                ll v = e.first, d = e.second;
                if (t + d > T) continue;
                dp[t+d][v] = (dp[t+d][v] + p*dp[t][u]) % MOD;
            }
        }
    }

    cout << dp[T][N-1] << endl;
}
