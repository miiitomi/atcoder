#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

bool dfs(vector<vector<int>> &G, int v, int t, int f, map<pair<int, int>, int> &C) {
    if (v == t) return true;
    for (int w : G[v]) {
        if (w == f) continue;
        if (dfs(G, w, t, v, C)) {
            int x = min(v, w);
            int y = max(v, w);
            C[make_pair(x, y)]++;
            return true;
        }
    }
    return false;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<vector<int>> G(N);
    map<pair<int, int>, int> C;
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (v < u) swap(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
        C[make_pair(u, v)] = 0;
    }

    for (int i = 0; i < M-1; i++) {
        dfs(G, A[i], A[i+1], -1, C);
    }

    ll S = 0;
    for (auto e = C.begin(); e != C.end(); e++) {
        S += e->second;
    }
    if (K + S < 0 || (K+S)%2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<ll>> dp(N-1, vector<ll>(1+(K+S)/2, 0));
    auto e = C.begin();
    dp[0][0]++;
    if (e->second <= (K+S)/2) dp[0][e->second]++;
    for (int i = 1; i < N-1; i++) {
        e++;
        for (int j = 0; j <= (K+S)/2; j++) {
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            if (j + e->second <= (K+S)/2) {
                dp[i][j + e->second] += dp[i-1][j];
                dp[i][j + e->second] %= MOD;
            }
        }
    }
    cout << dp[N-2][(K+S)/2] << endl;
}
