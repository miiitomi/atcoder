// https://atcoder.jp/contests/abc333/tasks/abc333_d
#include <bits/stdc++.h>
using namespace std;

void rec(int u, int p, vector<vector<int>> &G, vector<int> &d) {
    d[u] = 1;
    for (int v : G[u]) {
        if (v == p) continue;
        rec(v, u, G, d);
        d[u] += d[v];
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

    if (G[0].size() == 1) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> d(N, 0);
    rec(0, -1, G, d);

    int ans = d[0];
    int mv = -1;
    for (int v : G[0]) mv = max(mv, d[v]);
    ans -= mv;
    cout << ans << endl;
}
