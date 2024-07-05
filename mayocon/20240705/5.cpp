// https://atcoder.jp/contests/abc176/tasks/abc176_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    pair<int,int> s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    s.first--; s.second--; g.first--; g.second--;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<ll>> d(H, vector<ll>(W, INF));
    d[s.first][s.second] = 0;
    deque<pair<int,int>> Q;
    Q.push_back(s);

    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop_front();
        for (int k = 0; k < 4; k++) {
            int i = x+dx[k], j = y+dy[k];
            if (!is_in(i, j) || S[i][j] == '#' || d[i][j] <= d[x][y]) continue;
            d[i][j] = d[x][y];
            Q.push_front({i, j});
        }
        for (int i = max(0, x-2); i <= min(x+2, H-1); i++) {
            for (int j = max(0, y-2); j <= min(y+2, W-1); j++) {
                if (!is_in(i, j) || S[i][j] == '#' || d[i][j] <= d[x][y]+1) continue;
                d[i][j] = d[x][y]+1;
                Q.push_back({i, j});
            }
        }
    }

    if (d[g.first][g.second] == INF) cout << -1 << endl;
    else cout << d[g.first][g.second] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
