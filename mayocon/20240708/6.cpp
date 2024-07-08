// https://atcoder.jp/contests/abc217/tasks/abc217_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, M;
vector<vector<bool>> is_friend;
vector<vector<mint>> dp;

vector<mint> F(2001, 1);
vector<vector<mint>> C(2001, vector<mint>(2001, 0));

void rec(int l, int r) {
    dp[l][r] = 0;
    for (int x = l; x < r; x += 2) {
        for (int y = l+1; y < r; y+=2) {
            if (!is_friend[x][y]) continue;
            mint tmp = dp[l][x]*dp[x+1][y]*dp[y+1][r]*C[(x-l)/2+(y-(x+1))/2+(r-(y+1))/2][(x-l)/2]*C[(y-(x+1))/2+(r-(y+1))/2][(y-(x+1))/2];
            dp[l][r] += tmp;
        }
    }
}

void solve() {
    cin >> N >> M;
    dp.assign(2*N+1, vector<mint>(2*N+1, 0));
    for (int l = 0; l <= 2*N; l++) dp[l][l] = 1;
    is_friend.assign(2*N, vector<bool>(2*N, false));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        is_friend[a][b] = true;
    }
    for (int k = 2; k <= 2*N; k+=2) {
        for (int l = 0; l < 2*N; l++) {
            int r = l + k;
            if (r > 2*N) break;
            rec(l, r);
        }
    }
    cout << dp[0][2*N].val() << endl;
}

int main() {
    for (int x = 1; x <= 2000; x++) F[x] = F[x-1]*x;
    for (int n = 0; n <= 2000; n++) {
        for (int r = 0; r <= n; r++) {
            C[n][r] = F[n]/(F[n-r]*F[r]);
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
