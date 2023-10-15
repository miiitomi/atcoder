#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int b;
    int c;

    Edge(int to, int b, int c): to(to), b(b), c(c) {}
};

int N, M;
vector<vector<Edge>> G;

bool is_ok(double x) {
    vector<double> dp(N, -2e+9);
    dp[0] = 0.0;
    for (int u = 0; u < N-1; u++) {
        for (Edge &e : G[u]) {
            dp[e.to] = max(dp[e.to], dp[u] + e.b - x*e.c);
        }
    }
    return dp[N-1] >= 0.0;
}

int main() {
    cin >> N >> M;
    G.resize(N);
    double left=0.0, right=2e+9;
    for (int i = 0; i < M; i++) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        u--;
        v--;
        G[u].push_back(Edge(v, b, c));
    }

    while (right - left > 1e-10) {
        double x = (right + left) / 2.0;
        if (is_ok(x)) left = x;
        else right = x;
    }

    cout << fixed << setprecision(15) << left << endl;
}
