#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int id, to, weight;
    Edge(int id, int to, int weight) : id(id), to(to), weight(weight) {}
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(Edge(i, v, w));
        G[v].push_back(Edge(i, u, w));
    }

    vector<int> a(K), b(K);
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i];
    }

    vector<int> P(N, 5000);
    vector<int> B(M, 1);

    for (int i = 0; i < N; i++) {
        if (i != N-1) cout << P[i] << " ";
        else cout << P[i] << endl;
    }

    for (int i = 0; i < M; i++) {
        if (i != M-1) cout << B[i] << " ";
        else cout << B[i] << endl;
    }
}
