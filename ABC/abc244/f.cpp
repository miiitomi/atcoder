#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+8;

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

    const int K = (1 << N);
    vector<vector<int>> V(N, vector<int>(K, INF));  // V[i][S] = 最終点 i で状態 S の場合の最短パス
    queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) {
        V[i][0] = 0;
        Q.push(make_pair(i, 0));
    }

    while (!Q.empty()) {
        pair<int, int> p = Q.front();
        Q.pop();
        int v = p.first;
        int S = p.second;

        for (int w : G[v]) {
            bool b = ((S >> w) & 1);
            int T;
            if (b) T = S - (1 << w);
            else T = S + (1 << w);

            if (V[w][T] != INF) continue;

            V[w][T] = V[v][S] + 1;
            Q.push(make_pair(w, T));
        }
    }

    int ans = 0;
    for (int S = 0; S < K; S++) {
        int min_path = INF;
        for (int v = 0; v < N; v++) min_path = min(min_path, V[v][S]);
        ans += min_path;
    }

    cout << ans << endl;
}
