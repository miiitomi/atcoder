#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> p(K), h(K);
    for (int i = 0; i < K; i++) {
        cin >> p[i] >> h[i];
        p[i]--;
    }

    vector<int> height(N, -1);
    priority_queue<pair<int, int>> Q;
    for (int i = 0; i < K; i++) {
        height[p[i]] = h[i];
        Q.push(make_pair(h[i], p[i]));
    }

    while (!Q.empty()) {
        auto iter = Q.top();
        int h = iter.first;
        int u = iter.second;
        Q.pop();
        if (h != height[u]) continue;

        for (auto v : G[u]) {
            if (height[v] < height[u] -1) {
                height[v] = height[u] - 1;
                Q.push(make_pair(height[v], v));
            }
        }
    }

    int count = 0;
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        if (height[i] >= 0) {
            vec.push_back(i+1);
        }
    }

    cout << vec.size() << endl;
    for (int u : vec) cout << u << " ";
    cout << endl;
}
