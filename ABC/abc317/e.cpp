#include <bits/stdc++.h>
using namespace std;

vector<int> di{0, 0, -1, 1}, dj{1, -1, 0, 0};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];

    vector<vector<int>> G(H*W);
    int s, g;
    set<int> ng;

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char c = A[h][w];
            int dh=0, dw=0;
            if (c == '>') {
                dw = 1;
            } else if (c == 'v') {
                dh = 1;
            } else if (c == '<') {
                dw = -1;
            } else if (c == '^') {
                dh = -1;
            }
            int h_ = h+dh, w_ = w+dw;
            while (c != '.' && 0 <= h_ && h_ < H && 0 <= w_ && w_ < W && A[h_][w_] == '.') {
                ng.insert(h_*W + w_);
                h_ += dh;
                w_ += dw;
            }
            if (c == '.' || c == 'S') {
                for (int k = 0; k < 4; k++) {
                    int i = h + di[k], j = w + dj[k];
                    if (0 <= i && i < H && 0 <= j && j < W && (A[i][j] == '.' || A[i][j] == 'G')) {
                        G[h*W+w].push_back(i*W+j);
                    }
                }
            }
            if (c == 'S') s = h*W + w;
            else if (c == 'G') g = h*W + w;
        }
    }

    vector<int> d(H*W, -1);
    queue<int> Q;
    d[s] = 0;
    for (int v : G[s]) {
        if (ng.count(v)) continue;
        d[v] = 1;
        Q.push(v);
    }
    while (!Q.empty() && d[g] == -1) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] != -1 || ng.count(w)) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }

    cout << d[g] << endl;
}
