// https://atcoder.jp/contests/abc209/tasks/abc209_d
#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<vector<int>> G;
vector<int> c;

void dfs(int v, int p) {
    for (int w : G[v]) {
        if (w == p) continue;
        c[w] = - c[v];
        dfs(w, v);
    }
}

void solve() {
    cin >> N >> Q;
    G.resize(N);
    c.assign(N, 0);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    c[0] = 1;
    dfs(0, -1);

    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (c[x] == c[y]) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
