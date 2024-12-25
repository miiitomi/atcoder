// https://atcoder.jp/contests/abc089/tasks/abc089_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W, D;
    cin >> H >> W >> D;
    vector<pair<ll,ll>> B(H*W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a;
            cin >> a;
            a--;
            B[a] = {i, j};
        }
    }
    vector<ll> dp(H*W, INF);
    for (int s = 0; s < D; s++) {
        dp[s] = 0;
        for (int x = s; x+D < H*W; x += D) {
            dp[x + D] = dp[x] + abs(B[x].first - B[x+D].first) + abs(B[x].second - B[x+D].second);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << dp[r]-dp[l] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
