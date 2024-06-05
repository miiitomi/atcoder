// https://atcoder.jp/contests/abc239/tasks/abc239_f
#include <bits/stdc++.h>
using namespace std;

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
    int N, M;
    cin >> N >> M;

    vector<int> D(N);
    int sum_D = 0;
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        sum_D += D[i];
    }

    UnionFind uf(N);
    vector<vector<int>> G(N);
    for (int k = 0; k < M; k++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        uf.unite(a, b);
    }

    if (sum_D != 2*(N-1)) {
        cout << -1 << "\n";
        return;
    }

    vector<vector<int>> remain_vertex(N);

    for (int u = 0; u < N; u++) {
        if ((int)G[u].size() > D[u]) {
            cout << -1 << endl;
            return;
        }
        if ((int)G[u].size() < D[u]) {
            for (int num = 0; num < (D[u]-(int)G[u].size()); num++) remain_vertex[uf.root(u)].push_back(u);
        }
    }

    priority_queue<pair<int,int>> pq;
    for (int u = 0; u < N; u++) {
        if (!remain_vertex[u].empty()) {
            pq.push(make_pair((int)remain_vertex[u].size(), u));
        }
    }


    vector<pair<int,int>> V;
    while (!pq.empty()) {
        auto [su, u] = pq.top();
        pq.pop();

        if (pq.empty()) {
            cout << -1 << endl;
            return;
        }

        auto [sv, v] = pq.top();
        pq.pop();


        V.push_back({remain_vertex[u].back(), remain_vertex[v].back()});
        remain_vertex[u].pop_back();
        remain_vertex[v].pop_back();
        uf.unite(u, v);
        if (u != uf.root(u)) swap(u, v);

        while (!remain_vertex[v].empty()) {
            remain_vertex[u].push_back(remain_vertex[v].back());
            remain_vertex[v].pop_back();
        }
        if (!remain_vertex[u].empty()) {
            pq.push(make_pair((int)remain_vertex[u].size(), u));
        }
    }

    if (uf.size(0) != N) {
        cout << -1 << "\n";
        return;
    }

    for (auto p : V) {
        cout << p.first+1 << " " << p.second+1 << "\n";
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
