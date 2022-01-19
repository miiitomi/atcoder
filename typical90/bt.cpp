#include <bits/stdc++.h>
using namespace std;

int H, W;
int ans = -1;

void dfs(int v, int s, int h, vector<vector<int>> &G) {
    for (int nv : G[v]) {
        if (nv == s) {
            int counter = 0;
            for (int i = 0; i < H*W; i++) counter += (h >> i) & 1;
            ans = max(ans, counter);
        }

        if (h & (1 << nv)) continue;

        dfs(nv, s, h + (1 << nv), G);
    }
}

int main() {
    cin >> H >> W;

    vector<string> c(H);
    for (int i = 0; i < H; i++) cin >> c[i];

    vector<vector<int>> G(H*W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (c[i][j] == '#') continue;
            if (i < H - 1) {
                if (c[i+1][j] == '.') {
                    G[W*i + j].push_back(W*(i+1)+j);
                    G[W*(i+1) + j].push_back(W*i+j);
                }
            }
            if (j < W - 1) {
                if (c[i][j+1] == '.') {
                    G[W*i + j].push_back(W*i + j + 1);
                    G[W*i + j + 1].push_back(W*i + j);
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (c[i][j] == '#') continue;
            int s = W*i + j;
            dfs(s, s, (1 << s), G);
        }
    }

    if (ans < 3) cout << -1 << endl;
    else cout << ans << endl;
}
