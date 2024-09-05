// https://atcoder.jp/contests/abc225/tasks/abc225_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool cmp(const string &l, const string &r) {
    return (l+r) < (r+l);
}

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    sort(S.begin(), S.end(), cmp);
    vector<vector<string>> dp(N+1, vector<string>(N+1, string(2501, 'z')));
    dp[N][0] = "";
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = min(dp[i+1][j], S[i]+dp[i+1][max(0, j-1)]);
        }
    }
    cout << dp[0][K] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
