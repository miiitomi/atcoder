#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> L(N);
    vector<vector<ll>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        for (int j = 0; j < L[i]; j++) {
            ll x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    vector<map<ll, ll>> dp(N);
    for (ll x : a[0]) {
        if (dp[0].count(x)) {
            dp[0][x]++;
        } else {
            dp[0][x] = 1;
        }
    }
    for (int i = 1; i < N; i++) {
        for (ll x : a[i]) {
            for (auto m : dp[i-1]) {
                if (m.first * x > X) {

                } else if (dp[i].count(m.first * x)) {
                    dp[i][m.first * x] += m.second;
                } else {
                    dp[i][m.first * x] = m.second;
                }
            }
        }
    }

    if (dp[N-1].count(X)) {
        cout << dp[N-1][X] << endl;
    } else {
        cout << 0 << endl;
    }
}
