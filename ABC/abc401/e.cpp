#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> reached(N, false);
    int cnt = 0;
    dsu uf(N);
    for (int i = 0; i < N; i++) {
        if (!reached[i]) {
            reached[i] = true;
            cnt++;
        }
        for (int v: G[i]) {
            if (!reached[v]) {
                reached[v] = true;
                cnt++;
            }
            if (v < i) {
                uf.merge(v, i);
            }
        }

        if (uf.size(uf.leader(0)) == (i+1)) cout << cnt - (i+1) << "\n";
        else cout << -1 << "\n";
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
