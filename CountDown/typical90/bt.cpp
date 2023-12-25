#include <bits/stdc++.h>
using namespace std;

int H, W, N;
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int, int> to_pair(int x) {return make_pair(x / W, x % W);}
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
vector<string> c;

int main() {
    cin >> H >> W;
    N = H*W;
    c.resize(H);
    for (int i = 0; i < H; i++) cin >> c[i];
    vector<vector<int>> G(H*W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (c[i][j] == '#') continue;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y) || c[x][y] == '#') continue;
                G[to_int(i, j)].push_back(to_int(x, y));
            }
        }
    }

    int ans = -1e+9;
    for (int s = 0; s < N; s++) {
        if (G[s].size() == 0) continue;
        vector<vector<int>> dp((1 << N), vector<int>(N, -1e+9));
        dp[1 << s][s] = 1;
        for (int k = 0; k < (1 << N); k++) {
            for (int t = 0; t < N; t++) {
                if (dp[k][t] < 0) continue;
                for (int p : G[t]) {
                    if (p == s) ans = max(ans, dp[k][t]);
                    else if (k & (1 << p)) continue;
                    else dp[k + (1 << p)][p] = dp[k][t] + 1;
                }
            }
        }
    }

    if (ans >= 3) cout << ans << endl;
    else cout << -1 << endl;
}
