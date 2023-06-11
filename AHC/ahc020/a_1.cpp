#include <bits/stdc++.h>
using namespace std;

int N, M, K;

struct Edge {
    int id, to, weight;
    Edge(int id, int to, int weight) : id(id), to(to), weight(weight) {}
};

int hankei(int x, int y, int a, int b) {
    double d = (x-a)*(x-a) + (y-b)*(y-b);
    double q = sqrt(d);
    int r = (int)q;
    if (q - r > (double)0.0) r++;
    return r;
}

void nearest(vector<int> &x, vector<int> &y, vector<int> &a, vector<int> &b, vector<int> &P) {
    for (int i = 0; i < K; i++) {
        int min_h = 1e+5;
        int min_idx = -1;
        for (int j = 0; j < N; j++) {
            int h = hankei(x[j], y[j], a[i], b[i]);
            if (min_h > h) {
                min_h = h;
                min_idx = j;
            }
        }
        P[min_idx] = max(P[min_idx], min_h);
    }
}

int main() {
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

    vector<int> P(N, 0);
    vector<int> B(M, 1);

    nearest(x, y, a, b, P);

    for (int i = 0; i < N; i++) {
        if (i != N-1) cout << P[i] << " ";
        else cout << P[i] << endl;
    }

    for (int i = 0; i < M; i++) {
        if (i != M-1) cout << B[i] << " ";
        else cout << B[i] << endl;
    }
}
