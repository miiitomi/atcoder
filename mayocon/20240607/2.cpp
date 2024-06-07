// https://atcoder.jp/contests/abc196/tasks/abc196_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;

bool is_ok(ll x) {
    ll k = 1;
    ll y = x;
    while (y > 0) {
        y /= 10;
        k *= 10;
    }
    ll a = x + k*x;
    if (a <= N) return true;
    else return false;
}

void solve() {
    cin >> N;
    ll ans = 0;
    for (ll x = 1; x <= 1e+8; x++) {
        if (is_ok(x)) ans++;
        else break;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
