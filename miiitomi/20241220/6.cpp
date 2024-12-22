// https://atcoder.jp/contests/abc149/tasks/abc149_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> p2((int)2e+5 + 1, 1);
vector<mint> i2((int)2e+5 + 1, 1);

ll N;
vector<vector<int>> G;
vector<ll> cnt;
mint ans = 0;

void dfs(int u, int p) {
    mint tmp = i2[1] + i2[N];
    cnt[u] = 1;
    for (int v : G[u]) {
        if (v == p) continue; 
        dfs(v, u);
        cnt[u] += cnt[v];
        tmp += i2[N-cnt[v]] * (1 - i2[cnt[v]]);
    }
    if (p != -1) {
        int c = N-cnt[u];
        tmp += i2[N-c] * (1 - i2[c]);
    }
    ans += 1-tmp;
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cnt.assign(N, 0);
    dfs(0, -1);
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x <= (int)2e+5; x++) {
        p2[x] = p2[x-1]*2;
        i2[x] = p2[x].inv();
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
