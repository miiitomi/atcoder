// https://atcoder.jp/contests/abc308/tasks/abc308_d
#include <bits/stdc++.h>
using namespace std;

int H, W;

vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};

bool is_in(int h, int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

int to_int(int h, int w) {
    if (is_in(h, w)) return h*W + w;
    else return -1; 
}

string snuke = "snuke";

void dfs(int v, vector<vector<int>> &G, vector<bool> &reached) {
    for (int w : G[v]) {
        if (reached[w]) continue;
        reached[w] = true;
        dfs(w, G, reached);
    }
}

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> G(H*W);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char c = S[h][w];
            int k = snuke.find(c);
            if (0 <= k && k < 5) {
                char d = snuke[(k + 1) % 5];

                for (int p = 0; p < 4; p++) {
                    int x = h + dx[p], y = w + dy[p];
                    if (!is_in(x, y) || S[x][y] != d) continue;

                    G[to_int(h, w)].push_back(to_int(x, y));
                }
            }
        }
    }

    vector<bool> reached(H*W, false);
    reached[0] = true;
    dfs(0, G, reached);

    if (reached[H*W-1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
