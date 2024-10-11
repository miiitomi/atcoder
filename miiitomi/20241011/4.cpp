// https://atcoder.jp/contests/abc141/tasks/abc141_e
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
    preprocessing();
    int N;
    string S;
    cin >> N >> S;
    RollingHash rh(S);
    int left = 0, right = N;
    while (right - left > 1) {
        int m = (left + right)/2;
        map<ll, int> mp;
        bool ok = false;
        for (int i = 0; i+m <= N; i++) {
            ll h = rh.hash(i, i+m);
            if (!mp.contains(h)) mp[h] = i;
            else {
                if (mp[h]+m <= i) {
                    ok = true;
                    break;
                }
            }
        }
        if (ok) left = m;
        else right = m;
    }
    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
