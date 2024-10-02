// https://atcoder.jp/contests/abc224/tasks/abc224_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, S, T;
    double A, B;
    cin >> N >> S >> T >> A >> B;
    double left = B, right = INF;
    ll K = 1000;
    while (K--) {
        double x = (left + right) / 2;
        ll l = 0, r = T;
        while (r - l > 1) {
            ll m = (l + r)/2;
            if ((T-m)*A <= x) r = m;
            else l = m;
        }
        double y = B + (((T-r+1)*((T-r)*A))/2 + (N - (T-r+1)) * x)/N;
        if (y < x) right = x;
        else left = x;
    }
    double x = (left + right) / 2;
    ll l = 0, r = T;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if ((T-m)*A <= x) r = m;
        else l = m;
    }
    if (r <= S && S <= T) cout << (T-S)*A + 0.0 << endl;
    else cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
