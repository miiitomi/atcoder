// https://atcoder.jp/contests/abc338/tasks/abc338_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> Q(N), A(N), B(N);
    for (int i = 0; i < N; i++) cin >> Q[i];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    ll ans = -1;
    for (ll a = 0; a <= (int)1e+6; a++) {
        ll tmp = INF;
        for (ll i = 0; i < N; i++) {
            ll r = Q[i] - a*A[i];
            if (r < 0) tmp = -INF;
            else if (B[i] > 0) tmp = min(tmp, r/B[i]);
        }
        ans = max(ans, tmp+a);
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
