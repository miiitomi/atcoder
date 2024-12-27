// https://atcoder.jp/contests/abc244/tasks/abc244_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, M;
vector<vector<int>> G;
vector<int> path;
vector<int> tgt;
vector<int> cnt;

void dfs(int u, int p) {
    path.push_back(u);
    cnt[u] ^= 1;
    for (int v : G[u]) {
        if (v == p || ((int)G[v].size()==1 && tgt[v]==0)) continue;
        dfs(v, u);
        path.push_back(u);
        cnt[u] ^= 1;
        if (cnt[v] != tgt[v]) {
            path.push_back(v);
            cnt[v] ^= 1;
            path.push_back(u);
            cnt[u] ^= 1;
        }
    }
}

void solve() {
    cin >> N >> M;
    dsu UF(N);
    G.resize(N);
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (UF.same(u, v)) continue;
        UF.merge(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int r = 0;
    while ((int)G[r].size() > 1) r++;
    tgt.resize(N);
    cnt.assign(N, 0);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        tgt[i] = (c == '1');
    }
    dfs(r, -1);
    if (cnt[r] != tgt[r]) path.pop_back();
    cout << path.size() << "\n";
    for (int u : path) cout << u+1 << " ";
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
