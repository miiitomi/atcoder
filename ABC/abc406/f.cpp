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

void dfs(int u, int p, vector<int> &in, vector<int>& out, vector<int> &reached) {
    reached.push_back(u);
    for (auto [v, j]: G[u]) {
        if (v == p) continue;
        in[j] = reached.size();
        dfs(v, u, in, out, reached);
        out[j] = reached.size();
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
    vector<int> in, out, reached;
    in.resize(N-1);
    out.resize(N-1);
    dfs(0, -1, in, out, reached);
    vector<int> reverse_reached(N);
    for (int i = 0; i < N; i++) {
        int u = reached[i];
        reverse_reached[u] = i;
    }
    fenwick_tree<ll> F(N);
    for (int i = 0; i < N; i++) F.add(i, 1);

    int Q;
    cin >> Q;
    ll sum = N;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            ll x, w;
            cin >> x >> w;
            x--;
            ll y = reverse_reached[x];
            F.add(y, w);
            sum += w;
        } else {
            ll y;
            cin >> y;
            y--;
            ll tmp = F.sum(in[y], out[y]);
            ll tmp2 = sum - tmp;
            cout << abs(tmp - tmp2) << "\n";
        }
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
