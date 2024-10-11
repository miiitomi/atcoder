// https://atcoder.jp/contests/abc065/tasks/arc076_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

void solve() {
    int N;
    cin >> N;
    vector<pair<int,int>> V(N), X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
        X[i] = {V[i].first, i};
        Y[i] = {V[i].second, i};
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll,ll>>>> Q;
    for (int i = 0; i < N-1; i++) {
        Q.push({X[i+1].first-X[i].first, make_pair(X[i].second, X[i+1].second)});
        Q.push({Y[i+1].first-Y[i].first, make_pair(Y[i].second, Y[i+1].second)});
    }
    UnionFind uf(N);
    ll ans = 0;
    while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        ll c = p.first;
        auto [u, v] = p.second;
        if (uf.issame(u, v)) continue;
        ans += c;
        uf.unite(u, v);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
