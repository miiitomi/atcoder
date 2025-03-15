#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N, K;
vector<vector<int>> G;
vector<int> tmp;

bool dfs(int u, int p) {
    tmp[u] = 1;
    for (int v : G[u]) {
        if (v == p) continue;
        bool b = dfs(v, u);
        if (!b) return false;
        if (tmp[v] >= K) {
            continue;
        } else if (tmp[u] == 1) {
            tmp[u] = tmp[v] + 1;   
        } else if (tmp[u] + tmp[v] == K) {
            tmp[u] = K+1;
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> N >> K;
    G.resize(N*K);
    for (int i = 0; i < N*K-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int r = 0;
    while ((int)G[r].size() > 1) r++;
    tmp.resize(N*K);
    if (dfs(r, -1) && tmp[r] == K) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
