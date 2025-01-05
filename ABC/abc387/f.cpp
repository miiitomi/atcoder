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
    vector<int> A(N);
    scc_graph G(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        G.add_edge(i, A[i]);
    }
    auto V = G.scc();
    vector<int> r(N);
    for (int i = 0; i < (int)V.size(); i++) {
        auto &v = V[i];
        for (int u : v) r[u] = i;
    }
    vector<vector<int>> C(V.size());
    vector<bool> out(V.size(), false);
    for (int i = 0; i < N; i++) {
        int a = A[i];
        int x = r[i], y = r[a];
        if (x == y) continue;
        out[x] = true;
        C[y].push_back(x);
    }

    vector<vector<mint>> dp(V.size(), vector<mint>(M, 1));
    for (int u = 0; u < (int)V.size(); u++) {
        for (int v : C[u]) {
            mint tmp = 0;
            for (int l = 0; l < M; l++) {
                tmp += dp[v][l];
                dp[u][l] *= tmp;
            }
        }
    }

    mint ans = 1;
    for (int u = 0; u < (int)V.size(); u++) {
        if (out[u]) continue;
        mint tmp = 0;
        for (int k = 0; k < M; k++) tmp += dp[u][k];
        ans *= tmp;
    }
    cout << ans.val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
