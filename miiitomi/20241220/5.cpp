// https://atcoder.jp/contests/abc280/tasks/abc280_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<pair<ll,ll>>> G(N);
    dsu D(N);
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, -c});
        G[b].push_back({a, c});
        D.merge(a, b);
    }
    vector<ll> d(N, INF);
    for (int u = 0; u < N; u++) {
        if (u != D.leader(u)) continue;
        d[u] = 0;
        queue<int> Q;
        Q.push(u);
        bool done = false;
        while (!Q.empty() && !done) {
            int v = Q.front();
            Q.pop();
            for (auto &e : G[v]) {
                auto [to, c] = e;
                if (d[to] == INF) {
                    d[to] = d[v] + c;
                    Q.push(to);
                } else {
                    if (d[to] != d[v] + c) {
                        done = true;
                        d[u] = INF;
                        break;
                    }
                }
            }
        }
    }

    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (!D.same(x, y)) {
            cout << "nan\n";
        } else {
            int r = D.leader(x);
            if (d[r] == INF) {
                cout << "inf\n";
            } else {
                cout << d[x] - d[y] << "\n";
            }
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
