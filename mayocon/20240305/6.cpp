// https://atcoder.jp/contests/abc188/tasks/abc188_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll X;

map<ll, ll> mp;
ll rec(ll Y) {
    if (mp.count(Y)) return mp[Y];
    if (Y <= X) return mp[Y] = X - Y;
    if (Y % 2 == 1) return mp[Y] = min(abs(X-Y), min(rec((Y+1)/2)+2, rec((Y-1)/2)+2));
    return mp[Y] = min(abs(X-Y), rec(Y/2)+1);
}

void solve() {
    ll Y;
    cin >> X >> Y;
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
