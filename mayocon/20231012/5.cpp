// https://atcoder.jp/contests/abc271/tasks/abc271_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;
        B[i]--;
    }
    vector<ll> E(K);
    for (int i = 0; i < K; i++) {
        cin >> E[i];
        E[i]--;
    }

    vector<ll> dp(N, 1e+18);
    dp[0] = 0;

    for (int i = 0; i < K; i++) {
        int j = E[i];
        ll a = A[j], b = B[j], c = C[j];

        if (dp[a] == 1e+18) continue;
        dp[b] = min(dp[b], dp[a] + c);
    }

    if (dp[N-1] == 1e+18) cout << -1 << endl;
    else cout << dp[N-1] << endl;
}
