// https://atcoder.jp/contests/abc276/tasks/abc276_e
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;};
int s, t;
vector<string> C;

bool dfs(int i, int j, vector<vector<int>> &d) {
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (!is_in(x, y) || C[x][y] == '#') continue;
        if (C[x][y] == '.') {
            if (d[x][y] != -1) continue;
            d[x][y] = d[i][j] + 1;
            if (dfs(x, y, d)) return true;
        }
        if (C[x][y] == 'S' && d[i][j] >= 3) return true;
    }
    return false;
}

int main() {
    cin >> H >> W;
    C.resize(H);
    for (int i = 0; i < H; i++) cin >> C[i];

    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (C[i][j] == 'S') {
        s = i;
        t = j;
        break;
    }

    vector<vector<int>> d(H, vector<int>(W, -1));
    d[s][t] = 0;
    if (dfs(s, t, d)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
