// https://atcoder.jp/contests/abc146/tasks/abc146_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N;
vector<vector<pair<int,int>>> G;
vector<int> color;

void dfs(int u, int p, int c) {
    int k = 1;
    for (auto &e : G[u]) {
        auto [v, i] = e;
        if (v == p) continue;
        if (k == c) k++;
        color[i] = k;
        dfs(v, u, k);
        k++;
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    color.resize(N-1);
    dfs(0, -1, -1);
    cout << *max_element(color.begin(), color.end()) << "\n";
    for (int c : color) cout << c << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
