// https://atcoder.jp/contests/abc226/tasks/abc226_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(51, 1);

template<typename T> T mod_pow(T a, ll n) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    return res * res;
}
template<typename T> T mod_pow(T a, ll n, ll mod) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2, mod);
    if (n % 2 == 1) return res * res % mod * a % mod;
    return res * res % mod;
}

ll N, K;
mint ans = 0;
void f(vector<pair<ll,ll>> &V, ll &sum) {
    if (sum == N) {
        ll x = 1;
        mint y = F[N];
        for (auto &p : V) {
            auto [v, cnt] = p;
            x = lcm(x, v);
            y *= mod_pow(F[v-1], cnt) * mod_pow(F[v], cnt).inv() * F[cnt].inv();
        }
        ans += y * mod_pow(x, K, MOD);
        return;
    }
    int M = N;
    if (!V.empty()) M = V.back().first;
    for (int x = 1; x <= M && sum + x <= N; x++) {
        if (!V.empty() && x == V.back().first) {
            V.back().second++;
            sum += x;
            f(V, sum);
            V.back().second--;
            sum -= x;
        } else {
            V.push_back({x, 1});
            sum += x;
            f(V, sum);
            V.pop_back();
            sum -= x;
        }
    }
}

void solve() {
    cin >> N >> K;
    vector<pair<ll,ll>> V;
    ll sum = 0;
    f(V, sum);
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x <= 50; x++) F[x] = x * F[x-1];
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
