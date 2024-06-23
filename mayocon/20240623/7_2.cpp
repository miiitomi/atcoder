// https://atcoder.jp/contests/abc343/tasks/abc343_g
#include <bits/stdc++.h>
using namespace std;
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



void f(vector<string> &S, vector<vector<ll>> &TB) {
    int N = S.size();
    preprocessing();
    vector<RollingHash> rh(N);
    for (int i = 0; i < N; i++) rh[i] = RollingHash(S[i]);

    for (int i = N-1; i >= 0; i--) {
        bool can_erase = false;
        for (int j = 0; j < N; j++) {
            if ((int)S[i].size() > (int)S[j].size() || i == j) continue;
            for (int k = 0; k < (int)S[j].size(); k++) {
                if (k + S[i].size() > S[j].size()) continue;
                if (rh[i].hash(0) == rh[j].hash(k, k+S[i].size())) {
                    can_erase = true;
                }
            }
        }
        if (can_erase) {
            S.erase(S.begin() + i);
            rh.erase(rh.begin() + i);
            N--;
        }
    }

    TB.assign(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            for (int k = 1; k <= (int)min(S[i].size(), S[j].size()); k++) {
                if (rh[i].hash(S[i].size()-k) == rh[j].hash(0, k)) {
                    TB[i][j] = k;
                }
            }
        }
    }
}


void solve() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    vector<vector<ll>> TB;
    f(S, TB);
    N = S.size();

    vector<vector<ll>> dp((1 << N), vector<ll>(N, INF));
    for (int i = 0; i < N; i++) {
        dp[(1 << i)][i] = S[i].size();
    }
    for (int s = 0; s < (1 << N); s++) {
        for (int i = 0; i < N; i++) {
            if (dp[s][i] >= INF/2 || !(s & (1 << i))) continue;
            for (int j = 0; j < N; j++) {
                if (s & (1 << j)) continue;
                dp[s + (1 << j)][j] = min(dp[s + (1 << j)][j], dp[s][i] + (ll)S[j].size() - TB[i][j]);
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
