// https://atcoder.jp/contests/abc088/tasks/abc088_d
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}

void solve() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    int cnt = 0;
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (S[i][j] == '#') cnt++;
    vector<vector<int>> d(H, vector<int>(W, 1e+9));
    d[0][0] = 0;
    queue<pair<int,int>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int x = p.first + dx[k], y = p.second + dy[k];
            if (is_in(x, y) && S[x][y] == '.' && d[x][y] == (int)1e+9) {
                d[x][y] = d[p.first][p.second] + 1;
                Q.push(make_pair(x, y));
            }
        }
    }

    if (d.back().back() == (int)1e+9) cout << "-1\n";
    else cout << H*W - cnt - (d.back().back()+1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
