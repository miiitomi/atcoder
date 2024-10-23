// https://atcoder.jp/contests/abc235/tasks/abc235_e
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

struct Query {
    ll u, v, weight, idx;
    bool is_query, ans;
};

void solve() {
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<Query> V;
    for (int i = 0; i < M; i++) {
        Query q;
        cin >> q.u >> q.v >> q.weight;
        q.u--; q.v--;
        q.idx = i;
        q.is_query = false;
        V.push_back(q);
    }
    for (int i = 0; i < Q; i++) {
        Query q;
        cin >> q.u >> q.v >> q.weight;
        q.u--; q.v--;
        q.idx = i;
        q.is_query = true;
        V.push_back(q);
    }
    sort(V.begin(), V.end(), [](const Query &l, const Query &r) {return l.weight < r.weight;});
    UnionFind uf(N);
    for (Query &q : V) {
        if (q.is_query) {
            q.ans = !uf.issame(q.u, q.v);
        } else {
            uf.unite(q.u, q.v);
        }
    }
    sort(V.begin(), V.end(), [](const Query &l, const Query &r) {if (l.is_query != r.is_query) return l.is_query; return l.idx < r.idx;});

    for (int i = 0; i < Q; i++) {
        if (V[i].ans) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
