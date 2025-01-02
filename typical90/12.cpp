// https://atcoder.jp/contests/typical90/tasks/typical90_l
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

void solve() {
    cin >> H >> W;
    vector<bool> is_red(H*W, false);
    UnionFind U(H*W);
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            r--; c--;
            int x = to_int(r, c);
            is_red[x] = true;
            for (int k = 0; k < 4; k++) {
                int s = r + dx[k], t = c + dy[k];
                int y = to_int(s, t);
                if (is_in(s, t) && is_red[y]) U.unite(x, y);
            }
        } else {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--; b--; c--; d--;
            int x = to_int(a, b), y = to_int(c, d);
            if (is_red[x] && is_red[y] && U.issame(x, y)) cout << "Yes\n";
            else cout << "No\n";
        }
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
