#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> mp;

ll f(ll x) {
    if (x <= 1) return 0;
    if (mp.count(x)) return mp[x];
    if (x % 2 == 0) mp[x] = x + 2*f(x/2);
    else mp[x] = x + f(x/2) + f(x/2 + 1);
    return mp[x];
}

void solve() {
    ll N;
    cin >> N;
    cout << f(N) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
