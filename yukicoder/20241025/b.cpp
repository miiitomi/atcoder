#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    vector<string> G(H);
    for (int i = 0; i < H; i++) cin >> G[i];
    UnionFind uf(H*W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == '.') continue;
            int x = to_int(i, j);
            for (int k = 0; k < 4; k++) {
                int s = i + dx[k], t = j + dy[k];
                if (!is_in(s, t) || G[i][j] != G[s][t]) continue;
                uf.unite(x, to_int(s, t));
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int u = to_int(i, j);
            if (uf.size(uf.root(u)) < 4) continue;
            G[i][j] = '.';
        }
    }

    for (auto &s : G) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
