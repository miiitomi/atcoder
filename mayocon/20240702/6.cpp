// https://atcoder.jp/contests/abc257/tasks/abc257_f
#include <bits/stdc++.h>
using namespace std;

void func(int s, vector<vector<int>> &G, vector<int> &d) {
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (d[v] < (int)1e+9) continue;
            d[v] = d[u]+1;
            Q.push(v);
        }
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N+1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (u > 0) {
            G[u].push_back(v);
            G[v].push_back(u);
        } else {
            G[v].push_back(u);
        }
    }
    vector<int> d1(N+1, 1e+9), dn(N+1, 1e+9);
    func(1, G, d1);
    func(N, G, dn);

    for (int i = 1; i <= N; i++) {
        int ans = d1[N];
        ans = min(ans, d1[0]+dn[i]);
        ans = min(ans, d1[i]+dn[0]);
        ans = min(ans, d1[0]+dn[0]);
        if (ans >= (int)1e+9) cout << -1 << " ";
        else cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
