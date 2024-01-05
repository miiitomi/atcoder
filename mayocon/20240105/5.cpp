// https://atcoder.jp/contests/abc186/tasks/abc186_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD;

ll modinv(ll a) {
    // Check if a and MOD are coprime.
    ll b = MOD, u = 1, v = 0;
    while (b > 0) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

void solve() {
    int N, S, K;
    cin >> N >> S >> K;

    K = K % N;

    int g = gcd(N, gcd(S, K));
    N /= g;
    S /= g;
    K /= g;

    g = gcd(N, K);
    
    if (g != 1) {
        cout << -1 << endl;
        return;
    }

    MOD = N;
    ll n = (N-S) * modinv(K) % MOD;
    cout << n << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
