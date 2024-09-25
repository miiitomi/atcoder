// https://atcoder.jp/contests/abc351/tasks/abc351_d
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

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}
vector<string> S;

bool is_free(int r, int c) {
    if (S[r][c] == '#') return false;
    for (int k = 0; k < 4; k++) {
        int x = r + dx[k], y = c + dy[k];
        if (is_in(x, y) && S[x][y] == '#') return false;
    }
    return true;
}

void solve() {
    cin >> H >> W;
    S.resize(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    UnionFind uf(H*W);
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (!is_free(r, c)) continue;
            for (int k = 0; k < 4; k++) {
                int x = r + dx[k], y = c + dy[k];
                if (is_in(x, y) && is_free(x, y)) {
                    uf.unite(W*r+c, W*x+y);
                }
            }
        }
    }
    vector<int> d(H*W, 0);
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (S[r][c] == '#') {
                d[r*W+c] = 0;
                continue;
            }
            if (is_free(r, c)) {
                if (uf.root(r*W+c) == r*W+c) {
                    d[r*W+c] += uf.size(r*W+c);
                }
            } else {
                d[r*W+c] = 1;
                vector<int> done;
                for (int k = 0; k < 4; k++) {
                    int x = r + dx[k], y = c + dy[k];
                    if (is_in(x, y) && is_free(x, y) && (find(done.begin(), done.end(), uf.root(x*W+y))==done.end())) {
                        d[uf.root(x*W+y)]++;
                        done.push_back(uf.root(x*W+y));
                    }
                }
            }
        }
    }
    cout << *max_element(d.begin(), d.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
