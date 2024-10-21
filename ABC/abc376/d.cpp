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
    vector<vector<ll>> G(N+1);
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if (b == 0) b = N;
        G[a].push_back(b);
    }
    vector<ll> d(N+1, -1);
    d[0] = 0;
    queue<ll> Q;
    Q.push(0);
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (ll v : G[u]) {
            if (d[v] != -1) continue;
            d[v] = d[u]+1;
            Q.push(v);
        }
    }
    cout << d.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
