#include <bits/stdc++.h>
using namespace std;

vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};

void dfs(pair<int, int> v, map<pair<int, int>, vector<pair<int, int>>> &G, map<pair<int, int>, bool> &done) {
    done[v] = true;

    for (pair<int, int> p : G[v]) {
        if (!done[p]) dfs(p, G, done);
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> c(H);

    for (int i = 0; i < H; i++) cin >> c[i];

    map<pair<int, int>, vector<pair<int, int>>> G;
    map<pair<int, int>, bool> done;
    pair<int, int> s;
    pair<int, int> g;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (c[i][j] == 's') s = make_pair(i, j);
            else if (c[i][j] == 'g') g = make_pair(i, j);
            else if (c[i][j] == '#') continue;

            pair<int, int> p = make_pair(i, j);
            done[p] = false;
            G[p] = {};
            for (int k = 0; k < 4; k++) {
                int X = p.first + x[k];
                int Y = p.second + y[k];
                if (X >= 0 && X < H && Y >= 0 && Y < W) {
                    if (c[X][Y] != '#') {
                        G[p].push_back(make_pair(X, Y));
                    }
                }
            }
        }
    }

    dfs(s, G, done);

    if (done[g]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
