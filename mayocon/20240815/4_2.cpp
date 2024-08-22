// https://atcoder.jp/contests/abc185/tasks/abc185_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
const ll B = 1000;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    ll K = (N + B-1) / B;
    vector<ll> A(N), C(K, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[i/B] ^= A[i];
    }
    while (Q--) {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            x--;
            A[x] ^= y;
            C[x/B] ^= y;
        } else {
            x--;
            ll ans = 0;
            while (x < y) {
                if (x%B == 0 && x/B != y/B) {
                    ans ^= C[x/B];
                    x += B;
                } else {
                    ans ^= A[x];
                    x++;
                }
            }
            cout << ans << "\n";
        }
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
