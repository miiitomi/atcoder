#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int> > G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N, -1);
    dist[0] = 0;
    queue<int> Q;
    Q.push(0);

    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (int w : G[v]) {
            if (dist[w] == -1) {
                dist[w] = dist[v] + 1;
                Q.push(w);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << dist[i] << endl;
    }
}
