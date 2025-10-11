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
    vector<string> A(H);
    for (auto &s: A) cin >> s;
    pair<int,int> s, g;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 'S') s = {i, j};
            if (A[i][j] == 'G') g = {i, j};
        }
    }
    vector dp(H, vector(W, vector<ll>(2, -1)));
    dp[s.first][s.second][0] = 0;
    queue<pair<pair<int,int>,int>> Q;
    Q.push({s, 0});
    while (!Q.empty()) {
        auto [p, k] = Q.front();
        Q.pop();
        int d = dp[p.first][p.second][k];
        for (int i = 0; i < 4; i++) {
            pair<int,int> q = {p.first + dx[i], p.second + dy[i]};
            if (!is_in(q.first, q.second) || A[q.first][q.second] == '#') continue;
            if (k == 0 && A[q.first][q.second] == 'x') continue;
            if (k == 1 && A[q.first][q.second] == 'o') continue;
            int l = k;
            if (A[q.first][q.second] == '?') l = (l + 1) % 2;
            if (dp[q.first][q.second][l] != -1) continue;
            dp[q.first][q.second][l] = d + 1;
            Q.push({q, l});
        }
    }
    if (dp[g.first][g.second][0] == -1 && dp[g.first][g.second][1] == -1) cout << -1 << "\n";
    else if (dp[g.first][g.second][0] == -1) cout << dp[g.first][g.second][1] << "\n";
    else if (dp[g.first][g.second][1] == -1) cout << dp[g.first][g.second][0] << "\n";
    else cout << min(dp[g.first][g.second][0], dp[g.first][g.second][1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
