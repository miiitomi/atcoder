// https://atcoder.jp/contests/abc349/tasks/abc349_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> two_pow(1e+6, 1);

vector<ll> f(ll M) {
    vector<ll> v;
    for (ll x = 2; x*x <= M; x++) {
        if (M % x != 0) continue;
        ll y = 1;
        while (M % x == 0) {
            y *= x;
            M /= x;
        }
        v.push_back(y);
    }
    if (M > 1) v.push_back(M);
    return v;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    if (M == 1) {
        ll cnt = 0;
        while (N--) {
            ll a;
            cin >> a;
            if (a == 1) cnt++;
        }
        mint ans = two_pow[cnt]-1;
        cout << ans.val() << endl;
        return;
    }
    vector<ll> v = f(M);
    ll K = v.size();
    vector<ll> cnt(1LL << K, 0);
    while (N--) {
        ll a;
        cin >> a;
        if (M % a != 0) continue;
        ll i = 0;
        for (int k = 0; k < K; k++) {
            if (a % v[k] == 0) i += (1 << k);
        }
        cnt[i]++;
    }
    vector<mint> dp(1 << K, 0);
    dp[0] = 1;
    for (int i = 0; i < (1 << K); i++) {
        if (cnt[i] == 0) continue;
        vector<mint> ndp = dp;
        for (int j = 0; j < (1 << K); j++) {
            ndp[j | i] += dp[j] * (two_pow[cnt[i]] - 1);
        }
        swap(dp, ndp);
    }

    cout << dp[(1 << K) - 1].val() << endl;
}

int main() {
    for (int x = 1; x < (int)1e+6; x++) two_pow[x] = two_pow[x-1] * 2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
