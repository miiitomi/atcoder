#include <bits/stdc++.h>
using namespace std;

const string x = "snuke";
vector<int> di{-1, 1, 0, 0};
vector<int> dj{0, 0, -1, 1};

void dfs(int i, vector<vector<int>> &G, vector<bool> &reached) {
    reached[i] = true;
    for (int j : G[i]) {
        if (reached[j]) continue;
        dfs(j, G, reached);
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> G(H*W);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            int i = h * W + w;
            auto iter = find(x.begin(), x.end(), S[h][w]);
            int q = distance(x.begin(), iter);
            if (q == 5) continue;

            for (int k = 0; k < 4; k++) {
                int h_ = h + di[k];
                int w_ = w + dj[k];

                if (h_ < 0 || h_ >= H || w_ < 0 || w_ >= W) continue;
                int i_ = h_ * W + w_;
                auto iter_ = find(x.begin(), x.end(), S[h_][w_]);
                int q_ = distance(x.begin(), iter_);
                if (q_ == 5) continue;

                if ((q+1) % 5 == q_) {
                    G[i].push_back(i_);
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
