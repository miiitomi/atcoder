#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string N;
    cin >> N;
    ll ans = 0, K = N.size();

    for (ll s = 1; s <= 9*14; s++) {
        vector<vector<vector<vector<ll>>>> dp(K, vector<vector<vector<ll>>>(s+1, vector<vector<ll>>(s, vector<ll>(2, 0))));
        for (int a = 0; a <= (N[0] - '0') && a <= s; a++) {
            if (a == N[0]-'0') dp[0][a][a%s][1] = 1;
            else dp[0][a][a%s][0] = 1;
        }
        for (int i = 1; i < K; i++) {
            for (int x = 0; x <= s; x++) {
                for (int r = 0; r < s; r++) {
                    for (int f = 0; f <= 1; f++) {
                        for (int a = 0; a <= 9; a++) {
                            if (x + a > s || (f == 1 && a > (N[i]-'0'))) continue;
                            dp[i][x+a][(r*10+a)%s][f == 1 && a == (N[i]-'0')] += dp[i-1][x][r][f];
                        }
                    }
                }
            }
        }
        ans += dp[K-1][s][0][0] + dp[K-1][s][0][1];
    }

    cout << ans << endl;
}
