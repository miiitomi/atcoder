#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4e+18;

vector<pair<ll, ll>> ans;

void f(ll l, ll r) {
    if (l == r) return;
    pair<ll, ll> tmp;
    for (ll x = 1; x <= INF; x *= 2) {
        if ((l % x != 0) || (l > 0 && x > l)) break;
        ll j = l / x;
        if (x*(j+1) <= r) {
            tmp = make_pair(l, x*(j+1));
        }
    }
    ans.push_back(tmp);
    f(tmp.second, r);
}

void solve() {
    ll L, R;
    cin >> L >> R;
    f(L, R);
    cout << ans.size() << "\n";
    for (pair<ll, ll> p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
