// https://atcoder.jp/contests/abc284/tasks/abc284_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD, base;
vector<ll> power(1e+7, 1);

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

vector<ll> R, L;

void solve() {
    int N;
    string T;
    cin >> N >> T;
    R.assign(2*N+1, 0);
    L.assign(2*N+1, 0);
    for (int i = 2*N-1; i >= 0; i--) {
        char c = T[i];
        R[i] = (R[i+1] + (c - 'a' + 1) * power[2*N-1-i]) % MOD;
    }
    for (int i = 0; i <= 2*N-1; i++) {
        char c = T[i];
        L[i+1] = (L[i] + (c - 'a' + 1) * power[i]) % MOD;
    }

    for (int i = 0; i <= N; i++) {
        ll r = (R[i] - R[i+N] + MOD) % MOD * modinv(power[2*N-(i+N)]) % MOD;
        ll l = ((L[2*N] - L[2*N-(N-i)] + MOD) * modinv(power[2*N-(N-i) - i]) % MOD + L[i]) % MOD;
        if (l == r) {
            string S;
            for (int k = 0; k < N; k++) {
                S.push_back(T[i+k]);
            }
            reverse(S.begin(), S.end());
            cout << S << "\n";
            cout << i << "\n";
            return;
        }
    }

    cout << -1 << endl;
}


bool is_prime(ll M) {
    for (ll x = 2; x*x <= M; x++) {
        if (M % x == 0) return false;
    }
    return true;
}

void preprocessing() {
    random_device rnd;
    mt19937_64 engine(rnd());
    uniform_int_distribution<> udist(1e+9, 2e+9), udist2(100, 1e+8);
    do {
        MOD = udist(engine);
        base = udist2(engine);
    } while (!is_prime(MOD));

    for (int i = 1; i < 1e+7; i++) {
        power[i] = power[i-1] * base % MOD;
    }
}


int main() {
    preprocessing();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
