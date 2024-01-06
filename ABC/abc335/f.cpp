#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll B = 447;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> dp(N, 0);
    dp[0] = 1;

    vector<vector<ll>> s(B+1, vector<ll>(B, 0));

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int x = 1; x <= B; x++) dp[i] = (dp[i] + s[x][i % x]) % MOD;
        ans = (ans + dp[i]) % MOD;
        ll a = A[i];
        if (a <= B) {
            s[a][i % a] = (s[a][i % a] + dp[i]);
        } else {
            for (int y = i + a; y < N; y += a) {
                dp[y] = (dp[y] + dp[i]) % MOD;
            }
        }
    }

    cout << ans << endl;
}
