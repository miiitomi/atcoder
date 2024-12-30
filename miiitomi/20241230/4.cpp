// https://atcoder.jp/contests/abc266/tasks/abc266_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    dsu UF(N);
    int s=-1, t=-1;
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (UF.same(u, v)) {
            s = u, t = v;
            continue;
        }
        UF.merge(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> pre(N, -1);
    pre[s] = t;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (pre[v] != -1) continue;
            pre[v] = u;
            Q.push(v);
        }
    }
    vector<int> path(1, t);
    while (path.back() != s) {
        path.push_back(pre[path.back()]);
    }
    vector<int> d(N, -1);
    for (int u : path) d[u] = u;
    for (int u : path) {
        Q.push(u);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int w : G[v]) {
                if (d[w] != -1) continue;
                d[w] = d[v];
                Q.push(w);
            }
        }
    }

    int Queries;
    cin >> Queries;
    while (Queries--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (d[x] != d[y]) cout << "No\n";
        else cout << "Yes\n";
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
