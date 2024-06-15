#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4e+18;

int H, W;
vector<int> dx{1, -1, 0, 0, 0}, dy{0, 0, 1, -1, 0};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    ll K;
    cin >> H >> W >> K;
    vector<vector<ll>> A(H, vector<ll>(W, 0));
    vector<vector<ll>> dp(H, vector<ll>(W, -INF));
    ll si, sj;
    cin >> si >> sj;
    dp[si-1][sj-1] = 0;

    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];

    for (int k = 0; k <= min(2500LL, K); k++) {
        vector<vector<ll>> ndp = dp;
        for (int x = 0; x < H; x++) {
            for (int y = 0; y < W; y++) {
                for (int l = 0; l < 5; l++) {
                    int a = x + dx[l], b = y + dy[l];
                    if (!is_in(a, b)) continue;
                    ndp[a][b] = max(ndp[a][b], dp[x][y] + A[a][b]);
                }
            }
        }
        swap(ndp, dp);
        K--;
    }

    ll ans = -INF;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = max(ans, dp[i][j] + K*A[i][j]);
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
