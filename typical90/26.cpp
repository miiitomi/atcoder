// https://atcoder.jp/contests/typical90/tasks/typical90_z
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<vector<ll>> G;
vector<ll> d;

void dfs(int u, int p, int k) {
    d[u] = k;
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u, k+1);
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    d.assign(N, 0);
    for (int i = 0; i < N-1; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1, 0);
    vector<int> odd, even;
    for (int u = 0; u < N; u++) {
        if (d[u]%2) odd.push_back(u);
        else even.push_back(u);
    }
    if ((int)odd.size() < N/2) swap(odd, even);
    while ((int)odd.size() > N/2) odd.pop_back();
    for (int u : odd) cout << u+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
