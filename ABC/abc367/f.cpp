#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (1LL << 61) - 1;

// random management
random_device seed_gen;
mt19937_64 engine(seed_gen());
ll uniform_int(ll l, ll r) {uniform_int_distribution<ll> dist(l, r);return dist(engine);}

bool is_prime(ll N) {
    if (N <= 1) return false;
    for (ll x = 2; x*x <= N; x++) {
        if (N%x == 0) return false;
    }
    return true;
}

void solve() {
    ll N, Q;
    cin >> N >> Q;

    vector<ll> v(N);
    for (ll i = 0; i < N; i++) {
        v[i] = uniform_int(MOD/2, MOD-1);
    }
    vector<ll> A(N), B(N), SA(N+1, 0), SB(N+1, 0);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        SA[i+1] = (SA[i] + v[A[i]]) % MOD;
    }
    for (ll i = 0; i < N; i++) {
        cin >> B[i];
        B[i]--;
        SB[i+1] = (SB[i] + v[B[i]]) % MOD;
    }

    while (Q--) {
        ll l, r, L, R;
        cin >> l >> r >> L >> R;
        l--; L--;
        if ((MOD + SA[r] - SA[l])%MOD == (MOD + SB[R] - SB[L])%MOD) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
