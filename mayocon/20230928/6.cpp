// https://atcoder.jp/contests/abc201/tasks/abc201_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

void dfs(vector<vector<pair<int, ll>>> &G, int v, int from, vector<ll> &d) {
    for (auto p : G[v]) {
        int w = p.first;
        ll weight = p.second;
        if (w == from) continue;
        d[w] = d[v]^weight;
        dfs(G, w, v, d);
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<pair<int, ll>>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    vector<ll> d(N, 0);
    dfs(G, 0, -1, d);

    ll ans = 0;
    for (int v = 1; v < N; v++) ans = (ans + d[v]) % MOD;

    for (ll k = 0; k < 60; k++) {
        ll zero = 0, one = 0;
        for (int v = 1; v < N; v++) {
            if (d[v] & (1LL << k)) one++;
            else zero++;
        }
        ans = (ans + zero * one % MOD * mod_pow(2LL, k) % MOD) % MOD;
    }

    cout << ans << endl;
}
