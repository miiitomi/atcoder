// https://atcoder.jp/contests/abc219/tasks/abc219_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
const int B = 1000;

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> G(N);
    vector<set<int>> H(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        H[u].insert(v);
        H[v].insert(u);
    }
    vector<int> num(N), updated(N, 0);
    iota(num.begin(), num.end(), 0);
    vector<tuple<int,int,int>> T;
    for (int u = 0; u < N; u++) if ((int)G[u].size() >= B) T.push_back({u, 0, 0});

    for (int q = 1; q <= Q; q++) {
        int x;
        cin >> x;
        x--;
        for (int i = 0; i < (int)T.size(); i++) {
            auto [v, up, c] = T[i];
            if (up > updated[x] && H[x].contains(v)) {
                updated[x] = up;
                num[x] = c;
            }
        }

        int c = num[x];
        if ((int)G[x].size() >= B) {
            int i = distance(T.begin(), lower_bound(T.begin(), T.end(), make_tuple(x, 0, 0)));
            T[i] = make_tuple(x, q, c);
        } else {
            for (int v : G[x]) {
                updated[v] = q;
                num[v] = c;
            }
        }
    }

    for (int i = 0; i < (int)T.size(); i++) {
        auto [v, up, c] = T[i];
        for (int u : G[v]) {
            if (updated[u] < up) {
                updated[u] = up;
                num[u] = c;
            }
        }
    }

    for (int u = 0; u < N; u++) {
        cout << num[u]+1;
        if (u < N-1) cout << " ";
        else cout << "\n";
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
