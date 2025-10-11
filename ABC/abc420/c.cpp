#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N), B(N);
    for (ll &a: A) cin >> a;
    for (ll &b: B) cin >> b;
    ll ans = 0;
    for (int i = 0; i < N; i++) ans += min(A[i], B[i]);

    while (Q--) {
        char c;
        ll x, v;
        cin >> c >> x >> v;
        x--;
        ans -= min(A[x], B[x]);
        if (c == 'A') A[x] = v;
        else B[x] = v;
        ans += min(A[x], B[x]);
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
