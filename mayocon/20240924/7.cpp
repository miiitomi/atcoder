// https://atcoder.jp/contests/abc343/tasks/abc343_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const ll INF = 1e+18;

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

vector<string> S;
vector<RollingHash> rh;

void solve() {
    preprocessing();
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S.push_back(s);
        rh.push_back(RollingHash(s));
    }
    for (auto iter = S.begin(); iter != S.end(); ) {
        int i = distance(S.begin(), iter);
        bool is_contained = false;
        int n = S[i].size();
        for (int j = 0; j < (int)S.size(); j++) {
            if (i == j) continue;
            for (int k = 0; k + n < (int)S[j].size(); k++) {
                if (rh[j].hash(k, k+n) == rh[i].hash(0)) {
                    is_contained = true;
                    break;
                }
            }
            if (is_contained) break;
        }
        if (is_contained) {
            rh.erase(rh.begin() + i);
            iter = S.erase(iter);
        } else {
            iter++;
        }
    }
    N = S.size();
    vector<vector<ll>> d(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                d[i][j] = S[i].size();
                continue;
            }
            int tmp = 0;
            for (int k = 1; k <= min((int)S[j].size(), (int)S[i].size()); k++) {
                if (rh[i].hash(0, k) == rh[j].hash((int)S[j].size()-k, (int)S[j].size())) tmp = k;
            }
            d[i][j] = tmp;
        }
    }

    vector<vector<ll>> dp(1 << N, vector<ll>(N, INF));
    for (ll i = 0; i < N; i++) dp[1 << i][i] = S[i].size();
    for (ll s = 1; s < (1 << N); s++) {
        for (ll i = 0; i < N; i++) {
            if (dp[s][i] == INF) continue;
            for (ll j = 0; j < N; j++) {
                if (s & (1 << j)) continue;
                dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + (ll)S[j].size() - d[j][i]);
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < N; i++) ans = min(ans, dp[(1 << N)-1][i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
