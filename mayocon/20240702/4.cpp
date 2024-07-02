// https://atcoder.jp/contests/abc317/tasks/abc317_e
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];
    vector<vector<pair<int, char>>> R(H), C(W);
    pair<int,int> s, g;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c = A[i][j];
            if (c == '.') continue;
            else if (c == 'S') s = {i, j};
            else if (c == 'G') g = {i, j};
            else {
                R[i].push_back({j, c});
                C[j].push_back({i, c});
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] != '.') continue;
            auto iter = lower_bound(R[i].begin(), R[i].end(), make_pair(j, '.'));
            if (iter != R[i].end()) {
                char c = (*iter).second;
                if (c == '<') {
                    A[i][j] = '#';
                    continue;
                }
            }
            if (iter != R[i].begin()) {
                iter--;
                char c = (*iter).second;
                if (c == '>') {
                    A[i][j] = '#';
                    continue;
                }
            }
            auto iter2 = lower_bound(C[j].begin(), C[j].end(), make_pair(i, '.'));
            if (iter2 != C[j].end()) {
                char c = (*iter2).second;
                if (c == '^') {
                    A[i][j] = '#';
                    continue;
                }
            }
            if (iter2 != C[j].begin()) {
                iter2--;
                char c = (*iter2).second;
                if (c == 'v') {
                    A[i][j] = '#';
                    continue;
                }
            }
        }
    }

    vector<vector<int>> d(H, vector<int>(W, 1e+9));
    d[s.first][s.second] = 0;
    queue<pair<int,int>> Q;
    Q.push(s);
    while (!Q.empty()) {
        auto x = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int i = x.first + dx[k], j = x.second + dy[k];
            if (!is_in(i, j) || !(A[i][j] == '.' || A[i][j] == 'S' || A[i][j] == 'G') || d[i][j] < (int)1e+9) {
                continue;
            }
            d[i][j] = d[x.first][x.second]+1;
            Q.push({i, j});
        }
    }
    int ans = d[g.first][g.second];
    if (ans == (int)1e+9) ans = -1;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
