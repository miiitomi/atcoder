// https://atcoder.jp/contests/abc188/tasks/abc188_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 62);

ll X, Y;

map<ll,ll> mp;
ll rec(ll x) {
    if (mp.count(x)) return mp[x];
    ll tmp = abs(x - X);
    if (x <= X) return mp[x] = tmp;
    if (x % 2 == 1) {
        tmp = min(tmp, 1 + min(rec(x+1), rec(x-1)));
    } else {
        tmp = min(tmp, 1 + rec(x / 2));
    }
    return mp[x] = tmp;
}

void solve() {
    cin >> X >> Y;
    mp[X] = 0;
    cout << rec(Y) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
