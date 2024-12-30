// https://atcoder.jp/contests/abc282/tasks/abc282_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> T mod_pow(T a, ll n, ll mod) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2, mod);
    if (n % 2 == 1) return res * res % mod * a % mod;
    return res * res % mod;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = (N-1)*M;
    vector<pair<ll,pair<ll,ll>>> V;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            ll c = (mod_pow(A[i], A[j], M) + mod_pow(A[j], A[i], M))%M;
            V.push_back({M-c, make_pair(i, j)});
        }
    }
    sort(V.begin(), V.end());
    dsu UF(N);
    for (auto v : V) {
        auto [c, p] = v;
        if (UF.same(p.first, p.second)) continue;
        UF.merge(p.first, p.second);
        ans -= c;
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
