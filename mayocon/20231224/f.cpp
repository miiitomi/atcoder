// https://atcoder.jp/contests/abc260/tasks/abc260_f
#include <bits/stdc++.h>
using namespace std;

int main() {
    int S, T, M;
    cin >> S >> T >> M;
    vector<vector<int>> G(S);
    for (int k = 0; k < M; k++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v - S);
    }
    for (int i = 0; i < S; i++) if(G[i].size() > 1) sort(G[i].begin(), G[i].end());

    vector<vector<int>> X(T, vector<int>(T, -1));
    for (int s = 0; s < S; s++) {
        for (int i = 0; i < (int)G[s].size(); i++) {
            int u = G[s][i];
            for (int j = i+1; j < (int)G[s].size(); j++) {
                int v = G[s][j];
                if (X[u][v] == -1) X[u][v] = s;
                else {
                    cout << X[u][v]+1 << " " << s+1 << " " << S+u+1 << " " << S+v+1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
}
