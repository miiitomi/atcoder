#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, D;
    cin >> N >> D;
    vector<ll> T(N), L(N);
    for (int i = 0; i < N; i++) cin >> T[i] >> L[i];
    for (ll k = 1; k <= D; k++) {
        ll ans = -1;
        for (int i = 0; i < N; i++) {
            ans = max(ans, T[i]*(L[i] + k));
        }
        cout << ans << "\n";
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
