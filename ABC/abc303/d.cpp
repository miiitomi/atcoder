#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;

    bool caps = false;

    vector<vector<ll>> dp(2, vector<ll>((int)S.size() + 1, (ll)1e+17));
    dp[0][0] = 0;

    for (int i = 0; i < (int)S.size(); i++) {
        char s = S[i];

        if (s == 'a') {
            dp[0][i+1] = min(dp[0][i+1], dp[0][i] + X);
            dp[1][i+1] = min(dp[1][i+1], dp[0][i] + Z + Y);
            dp[0][i+1] = min(dp[0][i+1], dp[1][i] + Z + X);
            dp[1][i+1] = min(dp[1][i+1], dp[1][i] + Y);
        } else {
            dp[1][i+1] = min(dp[1][i+1], dp[1][i] + X);
            dp[0][i+1] = min(dp[0][i+1], dp[1][i] + Z + Y);
            dp[1][i+1] = min(dp[1][i+1], dp[0][i] + Z + X);
            dp[0][i+1] = min(dp[0][i+1], dp[0][i] + Y);
        }
    }

    cout << min(dp[0][(int)S.size()], dp[1][(int)S.size()]) << endl;
}
