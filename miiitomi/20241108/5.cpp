// https://atcoder.jp/contests/abc199/tasks/abc199_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;


vector<int> G;
ll ans;
vector<bool> reached;

void dfs(int u, vector<int> &path) {
    reached[u] = true;
    path.push_back(u);
    for (int v = 0; v < 20; v++) {
        if (reached[v] || !(G[u] & (1 << v))) continue;
        dfs(v, path);
    }
}

void f(vector<int> &v, int i, vector<int> &W) {
    if (i == (int)v.size()) {
        ans++;
        return;
    }
    int u = v[i];
    for (int k = 0; k < 3; k++) {
        bool is_ok = !(W[k] & G[u]);
        if (is_ok) {
            W[k] ^= (1 << u);
            f(v, i+1, W);
            W[k] ^= (1 << u);
        }
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    G.assign(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a] ^= (1 << b);
        G[b] ^= (1 << a);
    }
    ll tmp = 1;
    reached.assign(N, false);
    for (int i = 0; i < N; i++) {
        if (reached[i]) continue;
        vector<int> v;
        dfs(i, v);
        ans = 0;
        vector<int> W(3, 0);
        f(v, 0, W);
        tmp *= ans;
    }
    cout << tmp << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
