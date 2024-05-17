#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), S(N+1, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    reverse(A.begin(), A.end());
    for (int i = 0; i < N; i++) S[i+1] = (S[i] + A[i]) % MOD;

    ll ans = 0;
    for (int i = 0; i < N-1; i++) {
        ll tmp = 10;
        while (tmp <= A[i]) tmp *= 10;
        tmp %= MOD;
        ans = (ans + (A[i]*(N-i-1)%MOD) + ((S[N]-S[i+1]+MOD)%MOD)*tmp%MOD) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
