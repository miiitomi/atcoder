// https://atcoder.jp/contests/abc206/tasks/abc206_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll L, R;
    cin >> L >> R;
    vector<ll> ans(R+1, 0), tmp(R+1, 0);
    ll cnt = 0;
    for (ll g = R; g >= 2; g--) {
        ll l = (L+g-1) / g, r = (R+1+g-1) / g;
        ll n = r - l;
        tmp[g] = n*(n-1)/2;
        n = max(2LL, r) - max(2LL, l);
        ans[g] = n*(n-1)/2;
        for (ll y = 2*g; y <= R; y += g) {
            tmp[g] -= tmp[y];
            ans[g] -= tmp[y];
        }
        cnt += ans[g];
    }
    cout << 2*cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
