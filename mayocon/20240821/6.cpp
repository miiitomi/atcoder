// https://atcoder.jp/contests/abc358/tasks/abc358_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int H, W;
vector<int> dx{0, 1, -1, 0, 0}, dy{0, 0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    ll K, si, sj;
    cin >> H >> W >> K >> si >> sj;
    si--; sj--;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];

    vector<vector<ll>> dp(H, vector<ll>(W, -INF));
    dp[si][sj] = 0;
    for (int k = 0; k < H*W; k++) {
        vector<vector<ll>> ndp(H, vector<ll>(W, -INF));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                for (int l = 0; l < 5; l++) {
                    int x = i + dx[l], y = j + dy[l];
                    if (is_in(x, y)) {
                        ndp[i][j] = max(ndp[i][j], dp[x][y] + A[i][j]);
                    }
                }
            }
        }
        swap(dp, ndp);
        K--;
        if (K == 0) break;
    }

    ll ans = -INF;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = max(ans, dp[i][j] + K * A[i][j]);
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
