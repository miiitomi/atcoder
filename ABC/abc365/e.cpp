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
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;
    for (ll k = 0; k < 30; k++) {
        ll tmp = 0;
        ll odd = 0, even = 0;
        for (ll i = 0; i < N; i++) {
            if (A[i] & (1LL << k)) tmp++;
            if (tmp & 1) odd++;
            else even++;
        }

        for (ll i = 0; i < N; i++) {
            ans += odd * (1LL << k);
            if (A[i] & (1LL << k)) {
                ans -= (1 << k);
                odd--;
                swap(odd, even);
            } else {
                even--;
            }
        }
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
