// https://atcoder.jp/contests/abc170/tasks/abc170_f
#include <bits/stdc++.h>
using namespace std;

int H, W, K, sx, sy, tx, ty;


int main() {
    cin >> H >> W >> K >> sx >> sy >> tx >> ty;
    sx--;
    sy--;
    tx--;
    ty--;
    vector<string> c(H);
    for (int i = 0; i < H; i++) cin >> c[i];
    vector<set<int>> X(H), Y(W), F(H), G(W);
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (c[x][y] == '.') {
                X[x].insert(y);
                Y[y].insert(x);
            } else {
                F[x].insert(y);
                G[y].insert(x);
            }
        }
    }

    vector<vector<int>> d(H, vector<int>(W, 1e+9));
    queue<pair<int,int>> Q;
    d[sx][sy] = 0;
    Q.push(make_pair(sx, sy));
    X[sx].erase(sy);
    Y[sy].erase(sx);

    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();

        auto it1 = F[x].lower_bound(y);
        int r = min(W-1, y+K), l = max(0, y-K);
        if (it1 != F[x].end()) r = min(r, -1 + *it1);
        if (it1 != F[x].begin()) {
            it1--;
            l = max(l, 1 + *it1);
        }

        for (auto iter = X[x].lower_bound(l); iter != X[x].end() && *iter <= r; iter = X[x].erase(iter)) {
            d[x][*iter] = d[x][y] + 1;
            if (x == tx && *iter == ty) {
                cout << d[x][*iter] << "\n";
                return 0;
            }
            Y[*iter].erase(x);
            Q.push(make_pair(x, *iter));
        }

        auto it2 = G[y].lower_bound(x);
        r = min(H-1, x + K), l = max(0, x - K);
        if (it2 != G[y].end()) r = min(r, -1 + *it2);
        if (it2 != G[y].begin()) {
            it2--;
            l = max(l, 1 + *it2);
        }
        for (auto iter = Y[y].lower_bound(l); iter != Y[y].end() && *iter <= r; iter = Y[y].erase(iter)) {
            d[*iter][y] = d[x][y] + 1;
            if (*iter == tx && y == ty) {
                cout << d[*iter][y] << "\n";
                return 0;
            }
            X[*iter].erase(y);
            Q.push(make_pair(*iter, y));
        }
    }

    cout << -1 << endl;
}
