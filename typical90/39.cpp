// https://atcoder.jp/contests/typical90/tasks/typical90_am
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, ans = 0;
vector<vector<ll>> G;
vector<ll> siz;

void dfs(int u, int p, int k) {
    siz[u] = 1;
    ans += k*(N-1);
    for (int v: G[u]) {
        if (v == p) continue;
        dfs(v, u, k+1);
        ans -= 2LL*k*siz[u]*siz[v];
        siz[u] += siz[v];
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    siz.resize(N);
    dfs(0, -1, 0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
