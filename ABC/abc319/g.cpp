#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;
    vector<unordered_set<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].insert(v);
        G[v].insert(u);
    }

    vector<int> d(N, -1);
    d[N-1] = 0;
    queue<int> Q;
    Q.push(N-1);
    unordered_set<int> R;
    for (int i = 0; i < N-1; i++) R.insert(i);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        vector<int> reached;
        for (int w : R) {
            if (G[v].count(w)) continue;
            reached.push_back(w);
            d[w] = d[v] + 1;
            Q.push(w);
        }
        for (int w : reached) R.erase(w);
    }

    if (R.count(0)) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> dp(N, 0);
    dp[N-1] = 1;
    int K = d[0];
    vector<unordered_set<int>> V(K+1);
    V[0].insert(N-1);
    for (int i = 0; i < N; i++) {
        if (d[i] >= 1 && d[i] < K) V[d[i]].insert(i);
    }
    V[K].insert(0);

    for (int k = 1; k <= K; k++) {
        ll sum = 0;;
        for (int v : V[k-1]) sum = (sum + dp[v]) % MOD;
        for (int v : V[k]) {
            ll tmp = sum;
            for (int w : G[v]) if (V[k-1].count(w)) tmp = (tmp - dp[w] + MOD) % MOD;
            dp[v] = tmp;
        }
    }

    cout << dp[0] << endl;
}
