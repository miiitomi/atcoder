// https://atcoder.jp/contests/abc232/tasks/abc232_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> C(H);
    for (int h = 0; h < H; h++) cin >> C[h];

    vector<vector<int>> G(H*W);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (C[h][w] == '#') continue;

            int h_ = h+1, w_ = w;
            if (0 <= h_ && h_ < H && 0 <= w_ && w_ < W && C[h_][w_] == '.') G[W*h + w].push_back(W*h_ + w_);

            h_ = h;
            w_ = w+1;
            if (0 <= h_ && h_ < H && 0 <= w_ && w_ < W && C[h_][w_] == '.') G[W*h + w].push_back(W*h_ + w_);
        }
    }

    vector<int> d(H*W, -1);
    d[0] = 0;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] != -1) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }

    cout << 1 + *max_element(d.begin(), d.end()) << endl;
}
