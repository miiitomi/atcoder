// https://atcoder.jp/contests/abc277/tasks/abc277_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> G(2*N);
    for (int i = 0; i < M; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        u--;
        v--;
        if (a == 1) {
            G[2*u].push_back(make_pair(2*v, 1));
            G[2*v].push_back(make_pair(2*u, 1));
        } else {
            G[2*u+1].push_back(make_pair(2*v+1, 1));
            G[2*v+1].push_back(make_pair(2*u+1, 1));            
        }
    }
    for (int i = 0; i < K; i++) {
        int s;
        cin >> s;
        s--;
        G[2*s].push_back(make_pair(2*s+1, 0));
        G[2*s+1].push_back(make_pair(2*s, 0));
    }

    vector<int> d(2*N, -1);
    d[0] = 0;
    deque<int> Q;
    Q.push_front(0);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop_front();

        for (auto p : G[v]) {
            int w = p.first;
            int c = p.second;
            if (d[w] != -1) continue;
            d[w] = d[v] + c;
            if (c == 0) Q.push_front(w);
            else Q.push_back(w);
        }
    }

    int v = N-1;
    if (d[2*v] == -1 && d[2*v+1] == -1) cout << -1 << endl;
    else if (d[2*v] != -1 && d[2*v+1] != -1) cout << min(d[2*v], d[2*v+1]) << endl;
    else cout << max(d[2*v], d[2*v+1]) << endl;
}
