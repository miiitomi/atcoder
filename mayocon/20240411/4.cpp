// https://atcoder.jp/contests/abc166/tasks/abc166_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    map<ll, ll> mp;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        ans += mp[i - a];
        mp[i+a]++;
    }
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
