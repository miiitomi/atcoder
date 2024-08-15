// https://atcoder.jp/contests/abc325/tasks/abc325_c
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
vector<int> dx{-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy{-1, 0, 1, -1, 0, 1, -1, 0, 1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    vector<vector<ll>> S(H, vector<ll>(W, -1));
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            if (s[j] == '#') {
                S[i][j] = cnt;
                cnt++;
            }
        }
    }

    UnionFind uf(cnt);
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (S[x][y] == -1) continue;
            ll a = S[x][y];
            for (ll k = 0; k < 9; k++) {
                ll i = x + dx[k], j = y + dy[k];
                if (is_in(i, j) && S[i][j] != -1) {
                    ll b = S[i][j];
                    uf.unite(a, b);
                }
            }
        }
    }
    set<ll> st;
    for (ll u = 0; u < cnt; u++) st.insert(uf.root(u));
    cout << st.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
