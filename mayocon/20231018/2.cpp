// https://atcoder.jp/contests/abc177/tasks/abc177_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), S(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + A[i] * ((S[N] - S[i+1]) % MOD) % MOD) % MOD;
    }

    cout << ans << endl;
}
