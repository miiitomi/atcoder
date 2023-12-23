#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int H, W;
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return W*x + y;}
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};

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
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> A(H, vector<int>(W, -1));

    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                A[i][j] = cnt;
                cnt++;
            }
        }
    }

    UnionFind uf(cnt);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == -1) continue;
            int s = A[i][j];
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y) || A[x][y] == -1) continue;
                int t = A[x][y];
                uf.unite(s, t);
            }
        }
    }

    mint ans = 0;
    mint iv = ((mint)(H*W-cnt)).inv();
    set<int> st;
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (A[i][j] != -1) st.insert(uf.root(A[i][j]));
    int sz = st.size();

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] != -1) continue;
            set<int> st2;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y) || A[x][y] == -1) continue;
                st2.insert(uf.root(A[x][y]));
            }
            if (st2.size() == 0) ans += iv * (sz + 1);
            else ans += iv * (sz - ((int)st2.size() - 1));
        }
    }

    cout << ans.val() << endl;
}
