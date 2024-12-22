#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans = 0;
    for (int u = 0; u < N; u++) {
        vector<int> V(G[u].size(), 0);
        for (int i = 0; i < (int)G[u].size(); i++) {
            V[i] = G[G[u][i]].size()-1;
        }
        sort(V.begin(), V.end());
        ll M = V.size();
        for (int i = 0; i < M; i++) {
            ans = max(ans, 1 + (V[i]+1)*(M-i));
        }
    }
    cout << N-ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
