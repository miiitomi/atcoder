// https://atcoder.jp/contests/abc257/tasks/abc257_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs(ll N, vector<vector<int>> &G, vector<ll> &d, int s) {
    d.assign(N, 1e+9);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] < (int)1e+9) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> V;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a == -1) V.push_back(b);
        else {
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }

    vector<ll> d1, d2;
    bfs(N, G, d1, 0);
    bfs(N, G, d2, N-1);

    ll z = 1e+9;
    for (int x : V) z = min(z, d2[x]);

    ll w = 1e+9;
    for (int x : V) w = min(w, d1[x]);

    for (int i = 0; i < N; i++) {
        ll ans = d1[N-1];
        ans = min(ans, d1[i] + z + 1);
        ans = min(ans, w + 1 + d2[i]);
        ans = min(ans, w + 1 + 1 + z);
        if (ans >= 1e+9) cout << -1 << " ";
        else cout << ans << " ";
    }
    cout << endl;
}
