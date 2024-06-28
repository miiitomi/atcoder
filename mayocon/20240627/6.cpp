// https://atcoder.jp/contests/abc324/tasks/abc324_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    ll to;
    ll beauty;
    ll cost;
    Edge(ll t, ll b, ll c): to(t), beauty(b), cost(c) {};
};
ll N, M;
vector<vector<Edge>> G;

bool can(double x) {
    vector<double> dp(N, -(2e+9));
    dp[0] = 0;
    for (int u = 0; u < N; u++) {
        for (auto &e : G[u]) {
            dp[e.to] = max(dp[e.to], dp[u] + e.beauty - x*e.cost);
        }
    }
    return dp.back() >= 0.0;
}

void solve() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        ll u, v, b, c;
        cin >> u >> v >> b >> c;
        u--; v--;
        G[u].push_back(Edge(v, b, c));
    }

    double left = 0.0, right = 2e+9;
    for (int t = 0; t < 200; t++) {
        double x = (right+left)/2;
        if (can(x)) left = x;
        else right = x;
    }
    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
