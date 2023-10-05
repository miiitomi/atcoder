#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<vector<int>> &G, vector<int> &d) {
    d.assign(d.size(), -1);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] != -1) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int s = 0;
    vector<int> d(N, -1);
    bfs(s, G, d);
    s = distance(d.begin(), max_element(d.begin(), d.end()));
    bfs(s, G, d);

    cout << *max_element(d.begin(), d.end()) + 1 << endl;
}
