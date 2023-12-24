// https://atcoder.jp/contests/abc233/tasks/abc233_f
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

int N;
vector<int> P;
vector<vector<pair<int,int>>> G;
vector<int> d;

int dfs(int u, int p) {
    d[u] = 1;
    for (auto &e : G[u]) {
        int v = e.first;
        if (v == p) continue;
        d[u] += dfs(v, u);
    }
    return d[u];
}

int main() {
    cin >> N;
    P.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    UnionFind uf(N);
    G.resize(N);
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (uf.unite(a, b)) {
            G[a].push_back(make_pair(b, i+1));
            G[b].push_back(make_pair(a, i+1));
        }
    }
    d.assign(N, -1);
    for (int u = 0; u < N; u++) if (d[u] == -1) dfs(u, -1);

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    sort(v.begin(), v.end(), [](const int &i, const int &j){return d[i] < d[j];});

    vector<int> ans;
    for (int i : v) {
        int j = -1;
        for (int k = 0; k < N; k++) if (P[k] == i) j = k;
        if (i == j) continue;
        if (!uf.issame(i, j)) {
            cout << -1 << endl;
            return 0;
        }
        vector<pair<int,int>> prev(N, make_pair(-1, -1));
        prev[i].first = i;
        queue<int> Qu;
        Qu.push(i);
        while (!Qu.empty()) {
            int u = Qu.front();
            Qu.pop();
            for (auto &e : G[u]){
                int v = e.first, idx = e.second;
                if (prev[v].first != -1) continue;
                prev[v].first = u;
                prev[v].second = idx;
                Qu.push(v);
            }
        }

        while (j != i) {
            int k = prev[j].first;
            swap(P[j], P[k]);
            ans.push_back(prev[j].second);
            j = k;
        }
    }

    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
}
