// https://atcoder.jp/contests/abc244/tasks/abc244_f
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> V(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    int K = (1 << N);

    vector<vector<int>> G(K*N+1);
    for (int v = 0; v < N; v++) {
        G[K*N].push_back(K*v +(1 << v));
    }
    for (int s = 0; s < K; s++) {
        for (int v = 0; v < N; v++) {
            for (int w : V[v]) {
                G[K*v + s].push_back(K*w + (s ^ (1 << w)));
            }
        }
    }
    vector<int> d(K*N+1, 1e+9);
    d[K*N] = 0;
    queue<int> Q;
    Q.push(K*N);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] < 1e+9) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }

    int ans = 0;
    for (int s = 1; s < (1 << N); s++) {
        int tmp = 1e+9;
        for (int v = 0; v < N; v++) tmp = min(tmp, d[v*K+s]);
        ans += tmp;
    }

    cout << ans << endl;
}
