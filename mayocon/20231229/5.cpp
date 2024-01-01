// https://atcoder.jp/contests/abc142/tasks/abc142_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e+18;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    vector<vector<ll>> c(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        for (int j = 0; j < b[i]; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    vector<vector<ll>> dp(M+1, vector<ll>((1 << N), INF));
    dp[0][0] = 0;

    for (int i = 0; i < M; i++) {
        dp[i+1] = dp[i];
        for (int j = 0; j < (1 << N); j++) {
            int s = j;
            for (int k : c[i]) {
                if (!(s & (1 << k))) s += (1 << k);
            }
            dp[i+1][s] = min(dp[i+1][s], dp[i][j] + a[i]);
        }
    }

    ll ans = dp[M][(1 << N)-1];
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
