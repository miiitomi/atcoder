// https://atcoder.jp/contests/abc213/tasks/abc213_d
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> ans;
vector<bool> reached;

void dfs(int u, int p) {
    reached[u] = true;
    for (int v : G[u]) {
        if (reached[v]) continue;
        ans.push_back(v);
        dfs(v, u);
    }
    if (p != -1) ans.push_back(p);
    return;
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
    for (int u = 0; u < N; u++) {
        if (G[u].size() >= 2) sort(G[u].begin(), G[u].end());
    }
    reached.assign(N, false);
    ans.push_back(0);
    dfs(0, -1);

    for (int u : ans) cout <<u+1 << " ";
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
