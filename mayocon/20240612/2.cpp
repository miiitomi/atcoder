// https://atcoder.jp/contests/abc200/tasks/abc200_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<ll> cnt(200, 0);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        cnt[a%200]++;
    }

    ll ans = 0;
    for (ll x : cnt) {
        ans += x*(x-1)/2;
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
