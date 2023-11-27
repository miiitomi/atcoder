#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N+M);
    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int r;
            cin >> r;
            r--;
            G[r].push_back(N+i);
            G[N+i].push_back(r);
        }
    }

    vector<int> d(N+M, -1);
    d[0] = 0;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] != -1) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }

    for (int i = 0; i < N; i++) {
        if (d[i] == -1) cout << -1 << endl;
        else cout << d[i]/2 << endl;
    }
}
