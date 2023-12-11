// https://atcoder.jp/contests/abc299/tasks/abc299_e
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;

const int INF = 1e+9;
vector<vector<int>> d;

int main() {
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
    d.assign(N, vector<int>(N, INF));
    for (int s = 0; s < N; s++) {
        d[s][s] = 0;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int v : G[u]) {
                if (d[s][v] != INF) continue;
                d[s][v] = d[s][u] + 1;
                Q.push(v);
            }
        }
    }

    vector<int> c(N, 1);
    int K;
    cin >> K;
    vector<int> p(K), e(K);
    for (int i = 0; i < K; i++) {
        cin >> p[i] >> e[i];
        p[i]--;

        for (int j = 0; j < N; j++) {
            if (d[p[i]][j] < e[i]) c[j] = 0;
        }
    }

    for (int i = 0; i < K; i++) {
        int u = p[i];
        bool ok = false;
        for (int v = 0; v < N; v++) {
            if (d[u][v] == e[i] && c[v]) {
                ok = true;
            }
        }
        if (!ok) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for ( int i = 0; i < N; i++) {
        cout << c[i];
    }
    cout << endl;
}
