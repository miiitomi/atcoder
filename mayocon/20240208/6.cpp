// https://atcoder.jp/contests/abc257/tasks/abc257_f
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;

vector<int> compute_distance(int s, vector<vector<int>> &G) {
    int N = G.size();
    vector<int> d(N, INF);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (d[v] < INF) continue;
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
    return d;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N+1);
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u >= 0) {
            G[u].push_back(v);
            G[v].push_back(u);
        } else {
            G[v].push_back(N);
        }
    }

    vector<int> d = compute_distance(0, G);
    vector<int> e = compute_distance(N-1, G);

    for (int u = 0; u < N; u++) {
        int ans = d[N-1];
        ans = min(ans, d[u] + e[N]);
        ans = min(ans, d[N] + e[u]);
        ans = min(ans, d[N] + e[N]);
        if (ans >= INF) cout << -1 << " ";
        else cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
