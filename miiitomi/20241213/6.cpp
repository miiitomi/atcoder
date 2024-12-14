// https://atcoder.jp/contests/abc150/tasks/abc150_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;

ll base, MOD;
vector<ll> base_power(1e+7, 1);
void preprocessing() {
    // TODO: Run this function before using RollingHash.
    auto is_prime = [](ll x) -> bool {for (ll i = 2; i*i <= x; i++) if (x % i == 0) return false; return true;};
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    uniform_int_distribution<> dist_mod((ll)1e+9, (ll)2e+9);
    do {MOD = dist_mod(engine);} while(!is_prime(MOD));
    uniform_int_distribution<> dist_base(100, 10000);
    base = dist_base(engine);
    for (int i = 1; i < (ll)1e+7; i++) base_power[i] = base_power[i-1]*base%MOD;
}
struct RollingHash{
    char first_character = '0';  // TODO: Change first character if needed.
    ll n = 0;
    vector<ll> hashes;
    RollingHash() {};
    RollingHash(string &s) {
        n = s.size();
        hashes.assign(n+1, 0);
        for (int i = n-1; i >= 0; i--) hashes[i] = hashes[i+1]*base%MOD + (ll)(s[i] - first_character + 1);
    }
    ll hash(int l) {
        if (!(0 <= l && l <= n)) return -1;
        return hashes[l];
    }
    ll hash(int l, int r) {
        if (!(0 <= l && l <= r && r <= n)) return -1;
        return (hashes[l] - hashes[r]*base_power[r-l]%MOD + MOD)%MOD;
    }
};

void solve() {
    preprocessing();
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    vector<vector<vector<bool>>> ok(31, vector<vector<bool>>(2, vector<bool>(N, false)));
    for (int k = 0; k <= 30; k++) {
        string T(N, '0');
        for (int i = 0; i < N; i++) {
            if (B[i] & (1 << k)) T[i] = '1';
        }
        RollingHash rht(T);
        for (int x = 0; x <= 1; x++) {
            string S(2*N, '0');
            for (int i = 0; i < N; i++) {
                if ((x == 0 && (A[i] & (1 << k))) || (x == 1 && !(A[i] & (1 << k)))) {
                    S[i] = '1';
                    S[N+i] = '1';
                }
            }
            RollingHash rhs(S);
            for (int i = 0; i < N; i++) {
                if (rhs.hash(i, i+N) == rht.hash(0, N)) {
                    ok[k][x][i] = true;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        bool can = true;
        int tmp = 0;
        for (int k = 0; k <= 30; k++) {
            if (!ok[k][0][i] && !ok[k][1][i]) {
                can = false;
                break;
            } else if (ok[k][1][i]) {
                tmp ^= (1 << k);
            }
        }
        if (can) cout << i << " " << tmp << "\n";
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
