// https://atcoder.jp/contests/abc200/tasks/abc200_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<vector<ll>> dp(3, vector<ll>(3*N+1, 0));
    for (int i = 1; i <= N; i++) dp[0][i] = 1;

    for (int k = 1; k < 3; k++) {
        vector<ll> S(3*N+2, 0);
        for (int i = 0; i <= 3*N; i++) S[i+1] = S[i] + dp[k-1][i];
        for (int i = 0; i <= 3*N; i++) dp[k][i] = S[i] - S[max(0LL, i - N)];
    }

    ll x = 3;
    while (K - dp[2][x] > 0) {
        K -= dp[2][x];
        x++;
    }

    ll a = max(1LL, x - 2*N);
    ll b = max(1LL, x-a-N), c = min((ll)N, x-a-1);
    while (K - (c - b + 1) > 0) {
        K -= (c - b + 1);
        a++;
        b = max(1LL, x-a-N);
        c = min((ll)N, x-a-1);
    }

    b = b + K - 1;
    c = x - a - b;

    cout << a << " " << b << " " << c << endl;
}
