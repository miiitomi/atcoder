#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;

pair<int, int> dfs(int v, int f, vector<vector<int>> &G, vector<pair<int, int>> &P, int &n) {
    int l_min = INF;
    int r_max = -INF;

    for (int w : G[v]) {
        if (w == f) continue;
        pair<int, int> p = dfs(w, v, G, P, n);
        l_min = min(l_min, p.first);
        r_max = max(r_max, p.second);
    }

    if (l_min == INF) {
        pair<int, int> p = make_pair(n, n);
        P[v] = p;
        n++;
        return p;
    } else {
        pair<int, int> p = make_pair(l_min, r_max);
        P[v] = p;
        return p;
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int n = 1;
    vector<pair<int, int>> P(N);
    dfs(0, -1, G, P, n);

    for (int i = 0; i < N; i++) {
        pair<int, int> p = P[i];
        cout << p.first << " " << p.second << endl;
    }
}
