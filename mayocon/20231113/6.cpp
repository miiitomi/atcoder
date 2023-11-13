// https://atcoder.jp/contests/abc214/tasks/abc214_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e+9 + 7;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    vector<ll> dp(N, 0);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        char c = S[i];
        for (int j = i-2; j >= -2; j--) {
            if (j >= 0) dp[i] = (dp[i] + dp[j]) % MOD;
            else if (j == -2) dp[i] = (dp[i] + 1) % MOD;

            if (j >= -1 && S[j+1] == c) break;
        }
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
}
