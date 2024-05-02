// https://atcoder.jp/contests/abc292/tasks/abc292_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> cnt(N+1, 0);
    for (ll a = 1; a <= N; a++) {
        for (ll x = a; x <= N; x += a) cnt[x]++;
    }

    ll ans = 0;
    for (ll x = 1; x < N; x++) ans += cnt[x]*cnt[N-x];
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
