// https://atcoder.jp/contests/abc201/tasks/abc201_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<vector<pair<int, ll>>> G;
vector<ll> d;
const ll MOD = 1e+9 + 7;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

void dfs(int v, int par) {
    for (auto p : G[v]) {
        int nv = p.first;
        ll weight = p.second;
        if (nv == par) continue;
        d[nv] = d[v] ^ weight;
        dfs(nv, v);
    }
}

int main() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    d.assign(N, -1);
    d[0] = 0;
    dfs(0, -1);

    ll ans = 0;
    vector<vector<int>> cnt(60, vector<int>(2, 0));
    for (int v = 1; v < N; v++) {
        ans = (ans + d[v]) % MOD;
        for (ll k = 0; k < 60; k++) {
            if (d[v] & (1LL << k)) cnt[k][1]++;
            else cnt[k][0]++;
        }
    }

    for (int v = 1; v < N-1; v++) {
        for (ll k = 0; k < 60; k++) {
            if (d[v] & (1LL << k)) cnt[k][1]--;
            else cnt[k][0]--;
            ll c;
            if (d[v] & (1LL << k)) c = cnt[k][0];
            else c = cnt[k][1];
            ans = (ans + mod_pow(2, k)*c) % MOD;
        }
    }

    cout << ans << endl;
}
