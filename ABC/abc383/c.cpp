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
    ll D;
    cin >> H >> W >> D;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<ll>> d(H, vector<ll>(W, INF));
    queue<pair<ll,ll>> Q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'H') {
                d[i][j] = 0;
                Q.push({i, j});
            }
        }
    }
    while (!Q.empty()) {
        auto [i, j] = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (!is_in(x, y) || S[x][y] != '.') continue;
            if (d[x][y] > d[i][j] + 1) {
                d[x][y] = d[i][j] + 1;
                Q.push({x, y});
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] != '#' && d[i][j] <= D) ans++;
        }
    }
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
