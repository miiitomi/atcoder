// https://atcoder.jp/contests/abc151/tasks/abc151_d
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<string> S;
vector<int> dx{0, 0, -1, 1}, dy{1, -1, 0, 0};
vector<vector<int>> G;

bool is_in(int i, int j) {
    return (0 <= i && i < H && 0 <= j && j < W);
}

int to_int(int i, int j) {return W*i + j;}

int max_dist(int s, int t) {
    vector<int> d(H*W, 1e+9);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] < 1e+9) continue;
            if (w == t) return d[v] + 1;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }
}

int main() {
    cin >> H >> W;
    S.resize(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    G.resize(H*W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y) || S[x][y] == '#') continue;
                G[to_int(i, j)].push_back(to_int(x, y));
            }
        }
    }

    int ans = -1;
    for (int a = 0; a < H; a++) {
        for (int b = 0; b < W; b++) {
            if (S[a][b] == '#') continue;
            int s = to_int(a, b);
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    int t = to_int(i, j);
                    if (s == t || S[i][j] == '#') continue;
                    ans = max(ans, max_dist(s, t));
                }
            }
        }
    }

    cout << ans << endl;
}
