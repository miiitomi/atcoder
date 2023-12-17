#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> d;

int rec(int s, int par) {
    d[s] = 1;
    for (int w : G[s]) {
        if (w == par) continue;
        d[s] += rec(w, s);
    }
    return d[s];
}

int main() {
    cin >> N;
    G.resize(N);

    if (G[0].size() == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    d.assign(N, 1e+9);

    rec(0, -1);

    int mx = -1, sum = 0;
    for (int v : G[0]) {
        sum += d[v];
        mx = max(mx, d[v]);
    }

    cout << 1 + sum - mx << endl;
}
