// https://atcoder.jp/contests/abc148/tasks/abc148_f
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> dist_u, dist_v;
int u, v;

void dfs(int x, int par, vector<int> &dist) {
    for (int y : G[x]) {
        if (y == par) continue;
        dist[y] = dist[x] + 1;
        dfs(y, x, dist);
    }
}

void solve() {
    cin >> N >> u >> v;
    u--;
    v--;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dist_u.assign(N, 0);
    dist_v.assign(N, 0);
    dfs(u, -1, dist_u);
    dfs(v, -1, dist_v);

    if (dist_u[v] == 1 && (int)G[u].size() == 1) {
        cout << 0 << endl;
        return;
    }

    int ans = -1;
    for (int x = 0; x < N; x++) {
        if ((int)G[x].size() > 1 || dist_u[x] >= dist_v[x]) continue;
        int tmp = dist_v[x]-1;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
