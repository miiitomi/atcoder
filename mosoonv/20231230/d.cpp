// https://atcoder.jp/contests/abc138/tasks/abc138_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> d;
vector<vector<ll>> G;
vector<ll> ans;

void dfs(int u, int p, ll x) {
    for (ll y : d[u]) x += y;
    ans[u] += x;
    for (int v : G[u]) {
        if (v != p) dfs(v, u, x);
    }
}

int main() {
    ll N, Q;
    cin >> N >> Q;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    d.resize(N);
    for (int q = 0; q < Q; q++) {
        int p, x;
        cin >> p >> x;
        p--;
        d[p].push_back(x);
    }
    ans.assign(N, 0);
    dfs(0, -1, 0);

    for (ll a : ans) cout << a << " ";
    cout << endl;
}
