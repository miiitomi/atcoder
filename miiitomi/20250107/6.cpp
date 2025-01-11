// https://atcoder.jp/contests/abc272/tasks/abc272_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

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
    char first_character = 'a';  // TODO: Change first character if needed.
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
    ll N;
    string S, T;
    cin >> N >> S >> T;
    for (int i = 0; i < N; i++) {
        S.push_back(S[i]);
        T.push_back(T[i]);
    }
    RollingHash rhs(S), rht(T);
    vector<int> v = suffix_array(S), vs, vt;
    for (int i : v) if (i < N) vs.push_back(i);
    v = suffix_array(T);
    for (int i : v) if (i < N) vt.push_back(i);
    ll ans = 0;
    ll left = 0;
    for (int i : vs) {
        while (left < N) {
            int l = 0, r = N+1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                if (rhs.hash(i, i+m) == rht.hash(vt[left], vt[left]+m)) l = m;
                else r = m;
            }
            if (l < N && S[i+l] > T[vt[left]+l]) left++;
            else break;
        }
        ans += (N-left);
    }
    cout << ans << "\n";
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
