// https://atcoder.jp/contests/abc339/tasks/abc339_d
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    int N;
    cin >> N;
    H = N; W = N;
    int p = -1, q = -1;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'P') {
                if (p == -1) p = to_int(i, j);
                else q = to_int(i, j);
            }
        }
    }

    vector<vector<int>> d(N*N, vector<int>(N*N, INF));
    d[p][q] = 0;
    queue<pair<int,int>> Q;
    Q.push({p, q});
    while (!Q.empty()) {
        auto [a, b] = Q.front();
        Q.pop();
        auto [x1, y1] = to_xy(a);
        auto [x2, y2] = to_xy(b);

        for (int k = 0; k < 4; k++) {
            int s1 = x1+dx[k], t1 = y1+dy[k];
            if (!is_in(s1, t1) || S[s1][t1] == '#') {
                s1 = x1; t1 = y1;
            }
            int s2 = x2+dx[k], t2 = y2+dy[k];
            if (!is_in(s2, t2) || S[s2][t2] == '#') {
                s2 = x2; t2 = y2;
            }
            int u = to_int(s1, t1), v = to_int(s2, t2);
            if (d[u][v] != INF) continue;
            d[u][v] = d[a][b] + 1;
            Q.push({u, v});
        }
    }

    int ans = INF;
    for (int x = 0; x < N*N; x++) ans = min(ans, d[x][x]);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
