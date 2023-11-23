// https://atcoder.jp/contests/abc133/tasks/abc133_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<ll> c(N, -1);
    c[0] = K;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        int tmp = max(K-2, 0);
        if (v == 0) tmp = max(K-1, 0);
        for (int w : G[v]) {
            if (c[w] != -1) continue;
            c[w] = tmp;
            tmp = max(tmp-1, 0);
            Q.push(w);
        }
    }

    ll ans = 1;
    for (int v = 0; v < N; v++) ans = ans * c[v] % MOD;
    cout << ans << endl;
}
