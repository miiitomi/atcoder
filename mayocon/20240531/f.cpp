// https://atcoder.jp/contests/abc213/tasks/abc213_d
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> path;

void dfs(int u, int p) {
    path.push_back(u);
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    if (p != -1) path.push_back(p);
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < N; i++) sort(G[i].begin(), G[i].end());
    dfs(0, -1);

    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i]+1;
        if (i == (int)path.size()-1) cout << "\n";
        else cout << " ";
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
