// https://atcoder.jp/contests/abc237/tasks/abc237_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<vector<vector<ll>>>> dp(N, vector<vector<vector<ll>>>(M, vector<vector<ll>>(M+1, vector<ll>(M+1, 0))));
    for (int x = 0; x < M; x++) dp[0][x][M][M] = 1;

    for (int i = 0; i < N-1; i++) {
        for (int x = 0; x < M; x++) {
            for (int y = 0; y <= M; y++) {
                for (int z = 0; z <= M; z++) {
                    for (int a = 0; a <= min(z, M-1); a++) {
                        int s=x, t=y, u=z;
                        if (a < x) s = a;
                        else if (x < a && a < y) t = a;
                        else if (y < a && a < z) u = a;
                        dp[i+1][s][t][u] = (dp[i+1][s][t][u] + dp[i][x][y][z]) % MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int s = 0; s < M; s++) for (int t = 0; t < M; t++) for (int u = 0; u < M; u++) ans = (ans + dp[N-1][s][t][u]) % MOD;

    cout << ans << endl;
}
