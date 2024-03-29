// https://onlinejudge.u-aizu.ac.jp/problems/0531
#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

void rec(vector<vector<bool>> &G, int v, int w) {
    G[v][w] = true;
    for (int i = 0; i < 4; i++) {
        int x = v + dx[i];
        int y = w + dy[i];
        if (0 <= x && x < (int)G.size() && 0 <= y && y < (int)G[0].size()) {
            if (G[x][y]) continue;
            rec(G, x, y);
        }
    }
}

int main() {
    while (true) {
        int W, H, N;
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        cin >> N;
        vector<int> x1(N), y1(N), x2(N), y2(N);
        for (int i = 0; i < N; i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        vector<int> x, y;
        for (int i = 0; i < N; i++) {
            for (int d = -1; d <= 1; d++) {
                if (0 <= x1[i] + d && x1[i] + d <= W) x.push_back(x1[i] + d);
                if (0 <= x2[i] + d && x2[i] + d <= W) x.push_back(x2[i] + d);
                if (0 <= y1[i] + d && y1[i] + d <= H) y.push_back(y1[i] + d);
                if (0 <= y2[i] + d && y2[i] + d <= H) y.push_back(y2[i] + d);
            }
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        for (int i = 0; i < N; i++) {
            auto iter_x_1 = lower_bound(x.begin(), x.end(), x1[i]);
            auto iter_x_2 = lower_bound(x.begin(), x.end(), x2[i]);
            auto iter_y_1 = lower_bound(y.begin(), y.end(), y1[i]);
            auto iter_y_2 = lower_bound(y.begin(), y.end(), y2[i]);
            x1[i] = distance(x.begin(), iter_x_1);
            x2[i] = distance(x.begin(), iter_x_2);
            y1[i] = distance(y.begin(), iter_y_1);
            y2[i] = distance(y.begin(), iter_y_2);
        }
        W = (int)x.size() - 1;
        H = (int)y.size() - 1;

        vector<vector<bool>> G(W, vector<bool>(H, false));
        for (int i = 0; i < N; i++) {
            for (int v = x1[i]; v < x2[i]; v++) {
                for (int w = y1[i]; w < y2[i]; w++) {
                    G[v][w] = true;
                }
            }
        }

        int ans = 0;
        for (int v = 0; v < W; v++) {
            for (int w = 0; w < H; w++) {
                if (G[v][w]) continue;
                ans++;
                rec(G, v, w);
            }
        }

        cout << ans << endl;
    }
}
