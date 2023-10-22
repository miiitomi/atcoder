#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{0, 1, -1, 0, 1, -1, 0, 1, -1}, dy{0, 0, 0, 1, 1, 1, -1, -1, -1};
vector<string> S;

bool is_in(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

void dfs(int i, int j, vector<vector<bool>> &done) {
    for (int k = 0; k < 9; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (!is_in(x, y) || S[x][y] == '.' || done[x][y]) continue;
        done[x][y] = true;
        dfs(x, y, done);
    }
}

int main() {
    cin >> H >> W;
    S.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<vector<bool>> done(H, vector<bool>(W, false));
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.' || done[i][j]) continue;
            done[i][j] = true;
            ans++;
            dfs(i, j, done);
        }
    }

    cout << ans << endl;
}
