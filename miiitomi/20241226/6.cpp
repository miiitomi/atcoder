// https://atcoder.jp/contests/abc227/tasks/abc227_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void chmin(ll &v, ll nv) {
    if (v > nv) v = nv;
}

void solve() {
    ll H, W, K;
    cin >> H >> W >> K;
    vector<ll> v;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            v.push_back(A[i][j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            A[i][j] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i][j]));
        }
    }
    vector<vector<vector<vector<ll>>>> dp(H, vector<vector<vector<ll>>>(W, vector<vector<ll>>(v.size(), vector<ll>(H+W+1, INF))));
    for (int x = 0; x < (int)v.size(); x++) {
        if (x <= A[0][0]) dp[0][0][x][1] = v[A[0][0]];
        else dp[0][0][x][0] = 0;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int x = 0; x < (int)v.size(); x++) {
                for (int k = 0; k < H+W; k++) {
                    if (dp[i][j][x][k] == INF) continue;
                    if (i+1 < H) {
                        if (x <= A[i+1][j]) chmin(dp[i+1][j][x][k+1], dp[i][j][x][k]+v[A[i+1][j]]);
                        else chmin(dp[i+1][j][x][k], dp[i][j][x][k]);
                    }
                    if (j+1 < W) {
                        if (x <= A[i][j+1]) chmin(dp[i][j+1][x][k+1], dp[i][j][x][k]+v[A[i][j+1]]);
                        else chmin(dp[i][j+1][x][k], dp[i][j][x][k]);
                    }
                }
            }
        }
    }
    ll ans = INF;
    for (int x = 0; x < (int)v.size(); x++) {
        for (int k = K; k <= H+W; k++) {
            if (dp[H-1][W-1][x][k] == INF) continue;
            chmin(ans, dp[H-1][W-1][x][k] - (k - K)*v[x]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
