// https://atcoder.jp/contests/abc276/tasks/abc276_d
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
    ll g = 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) g = A[i];
        else g = gcd(g, A[i]);
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll r = A[i] / g;
        while (r % 2 == 0) {
            r /= 2;
            ans++;
        }
        while (r % 3 == 0) {
            r /= 3;
            ans++;
        }
        if (r != 1) {
            cout << -1 << endl;
            return;
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
