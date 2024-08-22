// https://atcoder.jp/contests/abc197/tasks/abc197_c
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
    vector<ll> A(N);
    for (ll &a : A) cin >> a;

    ll ans = INF;
    for (ll s = (1 << (N-1)); s < (1 << N); s++) {
        ll tmp_xor = 0, tmp_or = 0;
        for (int i = 0; i < N; i++) {
            tmp_or |= A[i];
            if (s & (1 << i)) {
                tmp_xor ^= tmp_or;
                tmp_or = 0;
            }
        }
        ans = min(ans, tmp_xor);
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
