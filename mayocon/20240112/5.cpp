// https://atcoder.jp/contests/abc147/tasks/abc147_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    for (ll k = 0; k <= 61; k++) {
        vector<ll> S(N+1, 0);
        for (int i = 0; i < N; i++) {
            S[i+1] = S[i];
            if (A[i] & (1LL << k)) S[i+1]++;
        }
        for (int i = 0; i < N-1; i++) {
            ll M = N-1-i;
            if (A[i] & (1LL << k)) M = M - (S[N] - S[i+1]);
            else M = S[N] - S[i+1];
            ans = (ans +  (1LL << k) % MOD * M % MOD) % MOD;
        }
    }
    cout << ans << endl;
}
