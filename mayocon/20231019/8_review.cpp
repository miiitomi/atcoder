// https://atcoder.jp/contests/abc319/tasks/abc319_g
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int N, M;
vector<ll> d, dp, V;
vector<unordered_set<int>> G;
vector<vector<int>> Vs;

ll rec_1(int v) {
    if (dp[v] != -1) return dp[v];

    int k = d[v];
    if (V[k] == -1) {
        V[k] = 0;
        for (int v : Vs[k-1]) V[k] = (V[k] + rec_1(v)) % MOD;    
    }
    dp[v] = V[k];

    for (int w : G[v]) if (d[w] != -1 && d[w] == d[v] - 1) dp[v] = (dp[v] - rec_1(w) + MOD) % MOD;
    return dp[v];
}

int main() {
    cin >> N >> M;
    d.assign(N, -1);
    dp.assign(N, -1);
    G.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].insert(v);
        G[v].insert(u);
    }

    unordered_set<int> Remain;
    for (int i = 1; i < N; i++) Remain.insert(i);
    queue<int> Q;
    Q.push(0);
    d[0] = 0;

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        vector<int> done;
        for (int w : Remain) {
            if (!G[v].count(w)) {
                done.push_back(w);
                d[w] = d[v] + 1;
                Q.push(w);
            }
        }
        for (int w : done) Remain.erase(w);
    }

    if (d[N-1] == -1) {
        cout << -1 << endl;
        return 0;
    }

    Vs.resize(d[N-1]+1);
    for (int v = 0; v < N; v++) if (d[v] >= 0 && d[v] <= d[N-1]) Vs[d[v]].push_back(v);

    V.assign(d[N-1]+1, -1);
    V[0] = 1;
    cout << rec_1(N-1) << endl;
}
