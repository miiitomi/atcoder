// https://atcoder.jp/contests/abc184/tasks/abc184_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll A, B, C;
    cin >> A >> B >> C;
    vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101, 0)));
    for (int a = 99; a >= 0; a--) {
        for (int b = 99; b >= 0; b--) {
            for (int c = 99; c >= 0; c--) {
                if (a == 0 && b == 0 && c == 0) continue;
                double sum = a + b + c;
                dp[a][b][c] = 1 + (dp[a+1][b][c]*a + dp[a][b+1][c]*b + dp[a][b][c+1]*c)/sum ;
            }
        }
    }
    cout << dp[A][B][C] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
