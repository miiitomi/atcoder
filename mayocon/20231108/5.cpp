// https://atcoder.jp/contests/abc184/tasks/abc184_e
#include <bits/stdc++.h>
using namespace std;

int H, W;
bool is_in(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
int to_int(int x, int y) {return W*x + y;}
pair<int, int> to_xy(int i) {return make_pair(i / W, i % W);}

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> v(26);
    vector<vector<int>> G(H*W + 26);

    int s = -1, t = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            else if (S[i][j] == 'S') s = to_int(i, j);
            else if (S[i][j] == 'G') t = to_int(i, j);
            else if (S[i][j] != '.') v[(int)(S[i][j] - 'a')].push_back(to_int(i, j));

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y) || S[x][y] == '#') continue;
                G[to_int(i, j)].push_back(to_int(x, y));
            }
        }
    }

    for (int c = 0; c < 26; c++) {
        for (int u : v[c]) {
            G[u].push_back(H*W + c);
            G[H*W + c].push_back(u);
        }
    }

    vector<int> d(H*W + 26, -1);
    d[s] = 0;
    deque<int> Q;
    Q.push_back(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop_front();
        for (int w : G[v]) {
            if (d[w] > -1) continue;
            if (w >= H*W) {
                d[w] = d[v];
                Q.push_front(w);
            } else {
                d[w] = d[v] + 1;
                Q.push_back(w);
            }
        }
    }

    cout << d[t] << endl;
}
