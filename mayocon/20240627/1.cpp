// https://atcoder.jp/contests/abc234/tasks/abc234_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
    return (x*x) + 2*x + 3; 
}

void solve() {
    ll t;
    cin >> t;
    ll ans = f(f(f(t)+t)+f(f(t)));
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
