// https://atcoder.jp/contests/abc311/tasks/abc311_d
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> S;
vector<vector<bool>> through, stop;

vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};

void dfs(int i, int j) {
    for (int k = 0; k < 4; k++) {
        int x = i, y = j;
        while (S[x + dx[k]][y + dy[k]] != '#') {
            x += dx[k];
            y += dy[k];
            through[x][y] = true;
        }
        if (!stop[x][y]) {
            stop[x][y] = true;
            dfs(x, y);
        }
    }
}

int main() {
    cin >> N >> M;
    S.resize(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    through.assign(N, vector<bool>(M, false));
    stop.assign(N, vector<bool>(M, false));
    through[1][1] = true;
    stop[1][1] = true;
    dfs(1, 1);

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (through[i][j]) cnt++;
        }
    }

    cout << cnt << endl;
}
