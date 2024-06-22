// https://atcoder.jp/contests/abc315/tasks/abc315_e
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;

void dfs(int u, vector<bool> &reached, vector<int> &path) {
    for (int v : G[u]) {
        if (reached[v]) continue;
        reached[v] = true;
        dfs(v, reached, path);
    }
    path.push_back(u);
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int u = 0; u < N; u++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int v;
            cin >> v;
            v--;
            G[u].push_back(v);
        }
    }
    vector<bool> reached(N, false);
    reached[0] = true;
    vector<int> path;
    dfs(0, reached, path);
    path.pop_back();

    for (int v : path) cout << v+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
