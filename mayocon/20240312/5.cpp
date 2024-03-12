// https://atcoder.jp/contests/abc213/tasks/abc213_e
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    int N = H * W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<pair<int,int>>> G(N);
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            for (int k = 0; k < 4; k++) {
                int i = x + dx[k], j = y + dy[k];
                if (is_in(i, j) && S[i][j] == '.') {
                    G[to_int(x, y)].push_back(make_pair(to_int(i, j), 0));
                }
            }
            for (int i = x-2; i <= x+2; i++) {
                for (int j = y-2; j <= y+2; j++) {
                    if (!is_in(i, j) || (i == x && j == y) || abs(i-x) + abs(j-y) == 4) continue;
                    G[to_int(x, y)].push_back(make_pair(to_int(i, j), 1));
                }
            }
        }
    }
    vector<int> d(N, 1e+9);
    d[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        int dist = Q.top().first, u = Q.top().second;
        Q.pop();
        if (dist != d[u]) continue;
        for (auto &e : G[u]) {
            int v = e.first, tmp = e.second;
            if (d[v] <= d[u] + tmp) continue;
            d[v] = d[u] + tmp;
            Q.push(make_pair(d[v], v));
        }
    }

    cout << d.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
