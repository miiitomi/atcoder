#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll _gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return _gcd(b, a%b);
}

ll _lcm(ll a, ll b) {
    return a * b / _gcd(a, b);
}

int main() {
    ll N, a, b, c;
    cin >> N >> a >> b >> c;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<ll>> X(N, vector<ll>(7, 0));
    vector<ll> v{a, b, c, _lcm(a, b), _lcm(b, c), _lcm(c, a), _lcm(a, _lcm(b, c))};

    for (int i = 0; i < N; i++) {
        ll a = A[i];
        for (int j = 0; j < 7; j++) {
            ll y = v[j];
            if (a % y != 0) X[i][j] = (a / y + 1) * y - a;
        }
    }

    vector<vector<ll>> dp = X;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 7; j++) dp[i][j] = min(dp[i][j], dp[i-1][j]);
        dp[i][3] = min(dp[i][3], dp[i-1][0] + X[i][1]);
        dp[i][3] = min(dp[i][3], dp[i-1][1] + X[i][0]);
        dp[i][4] = min(dp[i][4], dp[i-1][1] + X[i][2]);
        dp[i][4] = min(dp[i][4], dp[i-1][2] + X[i][1]);
        dp[i][5] = min(dp[i][5], dp[i-1][2] + X[i][0]);
        dp[i][5] = min(dp[i][5], dp[i-1][0] + X[i][2]);
        dp[i][6] = min(dp[i][6], dp[i-1][0] + X[i][4]);
        dp[i][6] = min(dp[i][6], dp[i-1][4] + X[i][0]);
        dp[i][6] = min(dp[i][6], dp[i-1][1] + X[i][5]);
        dp[i][6] = min(dp[i][6], dp[i-1][5] + X[i][1]);
        dp[i][6] = min(dp[i][6], dp[i-1][2] + X[i][3]);
        dp[i][6] = min(dp[i][6], dp[i-1][3] + X[i][2]);
    }

    cout << dp[N-1][6] << endl;
}
