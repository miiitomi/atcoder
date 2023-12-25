// https://atcoder.jp/contests/abc176/tasks/abc176_d
#include <bits/stdc++.h>
using namespace std;

int H, W;
int sx, sy, tx, ty;
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
vector<string> S;

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

int main() {
    cin >> H >> W >> sx >> sy >> tx >> ty;
    sx--;
    sy--;
    tx--;
    ty--;
    S.resize(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<pair<int,int>>> G(H*W);
    UnionFind uf(H*W);
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
        if (S[i][j] == '.') {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y) || S[x][y] == '#') continue;
                uf.unite(to_int(i, j), to_int(x, y));
                G[to_int(i, j)].push_back(make_pair(to_int(x, y), 0));
            }
        }
    }

    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
        unordered_set<int> st;
        int u = to_int(i, j);
        st.insert(uf.root(u));
        for (int x = i-2; x <= i+2; x++) {
            for (int y = j-2; y <= j+2; y++) {
                if (!is_in(x, y) || S[x][y] == '#') continue;
                int v = to_int(x, y);
                if (st.count(uf.root(v))) continue;
                G[u].push_back(make_pair(v, 1));
                st.insert(uf.root(v));
            }
        }
    }

    vector<int> d(H*W, 1e+9);
    int u = to_int(sx, sy);
    d[u] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push(make_pair(0, u));

    while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        int v = p.second, dist = p.first;
        if (dist != d[v]) continue;
        for (auto &e : G[v]) {
            int w = e.first, c = e.second;
            if (d[w] > d[v] + c) {
                d[w] = d[v] + c;
                Q.push(make_pair(d[w], w));
            }
        }
    }

    int g = to_int(tx, ty);
    if (d[g] == 1e+9) cout << -1 << endl;
    else cout << d[g] << endl;
}
