// https://atcoder.jp/contests/abc146/tasks/abc146_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll A, B, X;

ll f(ll x) {
    ll k = (to_string(x).size());
    return A*x + B*k;
}

void solve() {
    cin >> A >> B >> X;
    ll left = 0, right = (ll)1e+9 + 1;
    while (right - left > 1) {
        ll mid = (left + right)/2;
        ll x = f(mid);
        if (x <= X) left = mid;
        else right = mid;
    }
    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
