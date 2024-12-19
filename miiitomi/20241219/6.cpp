// https://atcoder.jp/contests/abc091/tasks/arc092_b
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
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    ll ans = 0;
    for (int k = 0; k < 30; k++) {
        vector<ll> a(N), b(N);
        for (int i = 0; i < N; i++) a[i] = A[i] % (1LL << (k+1));
        for (int i = 0; i < N; i++) b[i] = B[i] % (1LL << (k+1));
        sort(b.begin(), b.end());
        ll cnt = 0;
        for (ll x : a) {
            auto iter1 = lower_bound(b.begin(), b.end(), (1LL << k) - x);
            auto iter2 = lower_bound(b.begin(), b.end(), 2*(1LL << k) - x);
            auto iter3 = lower_bound(b.begin(), b.end(), 3*(1LL << k) - x);
            auto iter4 = lower_bound(b.begin(), b.end(), 4*(1LL << k) - x);
            cnt += distance(iter1, iter2) + distance(iter3, iter4);
        }
        if (cnt % 2) ans += (1LL << k);
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
