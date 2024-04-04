// https://atcoder.jp/contests/abc346/tasks/abc346_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    set<ll> A;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A.insert(a);
    }

    ll ans = (K + 1) * K / 2;
    for (ll a : A) if (a <= K) ans -= a;
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
