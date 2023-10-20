#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int b;
    int c;

    Edge(int _to, int _b, int _c): to(_to), b(_b), c(_c) {}
};

int N, M;
vector<vector<Edge>> G;

bool is_ok(double x) {
    vector<double> dp(N, -1e+9);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (auto &e : G[i]) {
            dp[e.to] = max(dp[e.to], dp[i] + e.b - x * e.c);
        }
    }
    return dp[N-1] >= 0.0;
}

int main() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        u--;
        v--;
        G[u].push_back(Edge(v, b, c));
    }

    double left = 0.0, right = 1e+5;
    while (right - left > 1e-11) {
        double mid = (right + left) / 2.0;
        if (is_ok(mid)) left = mid;
        else right = mid;
    }

    cout << fixed << setprecision(15) << left << endl;
}
