// https://atcoder.jp/contests/abc063/tasks/arc075_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    ll r = A - B;
    vector<ll> h(N);
    for (int i = 0; i < N; i++) cin >> h[i];
    ll left = 0, right = (ll)1e+9;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            ll x = max(0LL, h[i] - m * B);
            cnt += (x + r - 1)/r;
        }
        if (cnt <= m) right = m;
        else left = m;
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
