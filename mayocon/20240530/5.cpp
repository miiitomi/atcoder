// https://atcoder.jp/contests/abc299/tasks/abc299_e
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;
vector<vector<int>> dist;

vector<int> bfs(int s) {
    vector<int> d(N, -1);
    queue<int> Q;
    d[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (d[v] != -1) continue;
            d[v] = d[u]+1;
            Q.push(v);
        }
    }
    return d;
}

void solve() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dist.assign(N, vector<int>(N, 0));
    for (int s = 0; s < N; s++) dist[s] = bfs(s);

    string S(N, '1');
    int K;
    cin >> K;
    vector<int> p(K), d(K);
    for (int k = 0; k < K; k++) {
        cin >> p[k] >> d[k];
        p[k]--;

        for (int u = 0; u < N; u++) {
            if (dist[p[k]][u] < d[k]) S[u] = '0';
        }
    }

    for (int k = 0; k < K; k++) {
        int mv = 1e+9;
        for (int u = 0; u < N; u++) {
            if (S[u] == '1') mv = min(mv, dist[p[k]][u]);
        }

        if (mv != d[k]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    cout << S << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
