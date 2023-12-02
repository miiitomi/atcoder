#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;

vector<int> f(int s, vector<vector<int>> G) {
    vector<int> d(N, 1e+8);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] < (int)1e+8) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }
    return d;
}

int main() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }

    vector<int> d0 = f(0, G), dN1 = f(N-2, G), dN = f(N-1, G);

    int ans = min(d0[N-2] +dN1[N-1] + dN[0], d0[N-1]+dN[N-2]+dN1[0]);
    if (ans >= (int)1e+8) cout << -1 << endl;
    else cout << ans << endl;
}
