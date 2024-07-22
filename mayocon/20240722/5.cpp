// https://atcoder.jp/contests/abc104/tasks/abc104_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll D, G;
    cin >> D >> G;
    vector<ll> p(D), c(D);
    for (int i = 0; i < D; i++) cin >> p[i] >> c[i];

    ll ans = INF;
    for (ll s = 0; s < (1 << D); s++) {
        ll score = 0, tmp = 0;
        priority_queue<ll> Q;
        for (ll i = 0; i < D; i++) {
            if (s & (1 << i)) {
                score += 100*(i+1)*p[i] + c[i];
                tmp += p[i];
            } else {
                for (ll k = 0; k < p[i]; k++) Q.push(100*(i+1));
            }
        }

        while (score < G && !Q.empty()) {
            ll x = Q.top();
            Q.pop();
            score += x;
            tmp++;
        }

        if (score >= G) ans = min(ans, tmp);
    }

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
