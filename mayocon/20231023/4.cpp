// https://atcoder.jp/contests/abc088/tasks/abc088_d
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<string> S;

vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};

bool is_in(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

bool is_white(int i, int j) {
    return S[i][j] == '.';
}

int main() {
    cin >> H >> W;
    S.resize(H);
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; j < W; j++) cnt += (S[i][j] == '.');
    }

    vector<vector<int>> d(H, vector<int>(W, 1e+9));
    d[0][0] = 0;
    queue<pair<int,int>> Q;
    Q.push(make_pair(0, 0));

    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        int x = p.first, y = p.second;

        for (int k = 0; k < 4; k++) {
            int i = x + dx[k], j = y + dy[k];
            if (!is_in(i, j) || !is_white(i, j) || d[i][j] < (int)1e+9) continue;
            d[i][j] = d[x][y] + 1;
            Q.push(make_pair(i, j));
        }
    }

    if (d[H-1][W-1] == (int)1e+9) cout << -1 << endl;
    else cout << cnt - (d[H-1][W-1] + 1) << endl;
}
