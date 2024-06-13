// https://atcoder.jp/contests/abc270/tasks/abc270_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> d(N, -1);
    d[X] = X;
    queue<int> Q;
    Q.push(X);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (d[v] != -1) continue;
            d[v] = u;
            Q.push(v);
        }
    }

    vector<int> path;
    int s = Y;
    while (s != X) {
        path.push_back(s);
        s = d[s];
    }
    path.push_back(X);

    reverse(path.begin(), path.end());
    for (int x : path) cout << x + 1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
