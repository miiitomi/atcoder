#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

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
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            S[i][j] = '0';
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (is_in(x, y) && S[x][y] == '#') S[i][j] = '1';
            }
            if (S[i][j] == '0') cnt++;
        }
    }
    if (cnt == 0) {
        cout << 1 << endl;
        return;
    }
    UnionFind uf(H*W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] != '0') continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (is_in(x, y) && S[x][y] == '0') {
                    uf.unite(to_int(i, j), to_int(x, y));
                }
            }
        }
    }
    vector<int> tmp(H*W, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '0') {
                if (to_int(i, j) == uf.root(to_int(i, j))) {
                    tmp[to_int(i, j)] = uf.size(to_int(i, j));
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '1') {
                vector<int> v;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (is_in(x, y) && S[x][y] == '0') {
                        int r = uf.root(to_int(x, y));
                        v.push_back(r);
                    }
                }
                if (v.empty()) continue;
                sort(v.begin(), v.end());
                v.erase(unique(v.begin(), v.end()), v.end());
                for (int k : v) tmp[k]++;
            }
        }
    }

    cout << *max_element(tmp.begin(), tmp.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
