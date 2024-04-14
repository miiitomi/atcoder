#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll = long long;

vector<mint> pow2(1e+6, 1);

void solve() {
    ll N, M;
    cin >> N >> M;
    if (M == 1LL) {
        ll cnt = 0;
        while (N--) {
            ll a;
            cin >> a;
            if (a == 1LL) cnt++;
        }
        cout << (pow2[cnt] - 1).val() << endl;
        return;
    }

    vector<ll> A;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (M % a == 0) A.push_back(a);
    }
    N = (int)A.size();

    vector<ll> P;
    for (ll x = 2; x*x <= M; x++) {
        if (M % x == 0) {
            ll q = 1;
            while (M % x == 0) {
                q *= x;
                M /= x;
            }
            P.push_back(q);
        }
    }
    if (M != 1LL) P.push_back(M);

    ll K = P.size();
    vector<ll> cnt((1LL << K), 0);
    for (ll a : A) {
        ll s = 0;
        for (ll k = 0; k < K; k++) {
            if (a % P[k] == 0) s += (1LL << k);
        }
        cnt[s]++;
    }

    vector<mint> dp((1LL << K), 0);
    dp[0] = 1;
    for (ll s = 0; s < (1LL << K); s++) {
        if (cnt[s] == 0) continue;
        vector<mint> ndp = dp;
        for (ll t = 0; t < (1LL << K); t++) {
            if (dp[t] == 0) continue;
            ndp[s | t] += dp[t]*(pow2[cnt[s]]-1);
        }
        swap(dp, ndp);
    }

    cout << dp.back().val() << endl;
}

int main() {
    for (int x = 1; x < (int)1e+6; x++) pow2[x] = pow2[x-1] * 2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
