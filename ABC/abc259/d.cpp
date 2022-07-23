#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    int N;
    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    vector<ll> x(N), y(N), r(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    vector<int> S, T;
    for (int i = 0; i < N; i++) {
        if ((x[i] - sx)*(x[i] - sx) + (y[i] - sy)*(y[i] - sy) == r[i]*r[i]) {
            S.push_back(i);
        }
        if ((x[i] - tx)*(x[i] - tx) + (y[i] - ty)*(y[i] - ty) == r[i]*r[i]) {
            T.push_back(i);
        }
    }

    UnionFind uf(N);
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            ll d2 = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
            if (d2 <= (r[i]+r[j])*(r[i]+r[j])) {
                if (sqrt((double)d2) + min(r[i], r[j]) + 0.0001 >= max(r[i], r[j])) {
                    uf.unite(i, j);
                }
            }
        }
    }

    for (int s : S) {
        for (int t : T) {
            if (s == t) {
                cout << "Yes" << endl;
                return 0;
            } else if (uf.issame(s, t)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
