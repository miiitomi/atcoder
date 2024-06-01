#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;

    ll ans = 0;
    for (int k = 0; k <= 60; k++) {
        if (!(M & (1LL << k))) continue;
        ll X = N - (N % (1LL << (k+1)));
        ans = (ans + X/2) % MOD;
        if (N & (1LL << k)) {
            ll Y = (N % (1LL << k)) + 1;
            ans = (ans + Y) % MOD;
        }
    }

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
