#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n, ll m) {
    ll cnt = 0;
    while (n > 1) {
        ll h = n/2;
        n -= h;
        cnt++;
    }
    while (m > 1) {
        ll h = m/2;
        m -= h;
        cnt++;
    }
    return cnt;
}

void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    ll ans = 1 + min(min(f(a, m), f(n-a+1, m)), min(f(n, b), f(n, m-b+1)));
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
