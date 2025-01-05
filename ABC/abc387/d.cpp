#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 1e+9;
const ll MOD = 998244353;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    int s = -1, g = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') s = to_int(i, j);
            if (S[i][j] == 'G') g = to_int(i, j);
        }
    }
    vector<vector<int>> dp(H*W, vector<int>(2, INF));
    dp[s][0] = 0;
    dp[s][1] = 0;
    queue<pair<int,int>> Q;
    Q.push({s, 0});
    Q.push({s, 1});

    while (!Q.empty()) {
        auto [u, k] = Q.front();
        Q.pop();
        auto [x, y] = to_xy(u);
        for (int d = 0; d < 4; d++) {
            if (k == 0 && (d >= 2)) continue;
            if (k == 1 && (d <= 1)) continue;
            int a = x + dx[d], b = y + dy[d], c = 1 - k;
            int v = to_int(a, b);
            if (!is_in(a, b) || S[a][b] == '#' || dp[v][c] != INF) continue;
            dp[v][c] = dp[u][k]+1;
            Q.push({v, c});
        }
    }
    int ans = min(dp[g][0], dp[g][1]);
    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
