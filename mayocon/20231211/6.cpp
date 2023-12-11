// https://atcoder.jp/contests/abc244/tasks/abc244_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e+9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }


    vector<vector<int>> dp((1 << N), vector<int>(N, INF));
    dp[0] = vector<int>(N, 0);
    ll ans = 0;

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> Q;
    for (int i = 0; i < N; i++) Q.push(make_pair(0, make_pair(0, i)));

    while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        int d = p.first, s = p.second.first, u = p.second.second;
        if (dp[s][u] != d) continue;
    
        for (int v : G[u]) {
            if (dp[s ^ (1 << v)][v] > dp[s][u] + 1) {
                dp[s ^ (1 << v)][v] = dp[s][u] + 1;
                Q.push(make_pair(dp[s ^ (1 << v)][v], make_pair(s ^ (1 << v), v)));
            }
        }
    }

    for (int s = 0; s < (1 << N); s++) {
        int tmp = INF;
        for (int i = 0; i < N; i++) {
            tmp = min(tmp, dp[s][i]);
        }
        ans += tmp;
    }

    cout << ans << endl;
}
